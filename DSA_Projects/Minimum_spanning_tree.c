/*
 Your task is to construct an undirected graph without loops based on the list of edges given in the input and then perform the following operations on this graph according to the input:
i - insert - inserting a new edge into the graph
s - search - search for the minimal skeleton in the graph that contains the specified vertex
u - update - modification of an existing edge in the graph (i.e. modification of the weight of the given edge), while the weight of the edge must not be changed to a negative number
d - delete - remove an existing edge from the graph

An edge is defined as a pair of two vertices, while the vertices are numbered with non-negative whole numbers from 0 to N, where N is the maximum number of vertices in the given graph.

If the given operation fails, the error message " failed" is printed in a separate line.
The failure is, for example, when we try to add an edge that already exists, or when the search operation did not find any skeleton for the specified vertex (i.e. not a single edge).

The input of the program is the number N (max. number of vertices in the graph).
Then there are lines, where in each line there is one edge of the initial graph, in the format "(vertex_1, vertex2, weight)".
This initial graph is followed by any number of lines, each line representing one command for one operation (ie, insert, search, update, or delete).
The operation is expressed by the initial letter, i.e. i, s, u or d. The following are the data required for the given operation.
The insert operation needs the following 3 data: vertex_1 number, vertex_2 number, edge weight (also an integer)
The search operation needs this 1 piece of data: the number of the vertex that the minimal skeleton of the graph should contain
The update operation needs the following 3 data: number of vertex_1, number of vertex_2, change of edge weight (also an integer)
The delete operation needs the following 2 data: vertex_1 number, vertex_2 number

The output is the minimal skeletons found by search operations, while the output format is as follows:
: [(vertex1, vertex2), (vertex2, vertex3), ..., (vertex_X, last_vertex)]
Edges are sorted In addition, the above-mentioned error messages are also output in case of operation failure, together with the edge/vertex above which/the given operation failed.

Ukážkový vstup
6
(3, 0, 163678189)
(3, 2, 116110502)
(3, 1, 636291174)
(3, 4, 604309580)
(3, 5, 742450723)
(0, 4, 982660960)
(0, 1, 214645293)
(0, 5, 848684709)
(0, 2, 276073530)
(2, 4, 233742802)
(4, 5, 578621347)
(1, 5, 888487121)
s 0
i 5 2 1033963
d 3 0
i 4 1 130237511
u 0 4 -50786606
u 3 5 -64503537
d 4 5
d 2 5
d 3 1
u 3 2 81792993
i 2 1 56503429
d 3 5
d 2 1
s 3
d 1 5
i 1 3 17267236
s 3
d 2 4
s 2
u 3 4 71148930
i 2 4 125219305
s 3
i 5 3 146438595
d 0 2
u 2 4 71674226
i 5 2 77894607
s 3
u 3 2 55074367
u 3 5 -77515144
i 2 0 40796343
d 3 5
s 2
d 0 5
s 3
d 3 2
d 3 1
u 0 4 24714783
d 2 4
u 2 5 56498429
s 4
d 4 1
d 0 1
s 4
u 2 5 32874073
s 5
d 0 2
i 0 3 158996028
s 1
u 3 0 -14905679
s 5
d 0 4
s 5
u 3 0 -60486727
s 2
d 3 0
i 0 5 92405740
d 3 4
u 2 5 -47624317
i 3 5 24173816
s 0

Ukážkový výstup
1306798133: [(0, 1), (0, 3), (2, 3), (2, 4), (4, 5)]
1625213810: [(0, 1), (0, 5), (1, 4), (2, 3), (2, 4)]
1408738244: [(0, 1), (0, 5), (1, 3), (1, 4), (2, 3)]
1408738244: [(0, 1), (0, 5), (1, 3), (1, 4), (2, 3)]
1336054054: [(0, 1), (0, 5), (1, 3), (1, 4), (2, 4)]
586483242: [(0, 1), (1, 3), (1, 4), (2, 5), (3, 5)]
463089228: [(0, 2), (1, 3), (1, 4), (2, 4), (2, 5)]
463089228: [(0, 2), (1, 3), (1, 4), (2, 4), (2, 5)]
1195530693: [(0, 1), (0, 2), (1, 4), (2, 5), (3, 4)]
1807237026: [(0, 2), (0, 4), (2, 5), (3, 4)]
1840111099: [(0, 2), (0, 4), (2, 5), (3, 4)]
search 1 failed
167267109: [(2, 5)]
167267109: [(2, 5)]
167267109: [(2, 5)]
236222348: [(0, 5), (2, 5), (3, 5)]
 */


#include <stdio.h>
#include <stdlib.h>

#define INFINITY_VALUE 999999999
#define UNDEFINED_VALUE -1
int prenos = 0;

typedef struct Node {
    int vertex;
    long int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertex;
    Node** adjList;
} Graph;

typedef struct {
    int first;
    int second;
} Pair;

int comparePairs(const void* a, const void* b) {
    Pair* pair1 = (Pair*)a;
    Pair* pair2 = (Pair*)b;

    if (pair1->first != pair2->first) {
        return pair1->first - pair2->first;
    }else {
        return pair1->second - pair2->second;
    }
}

Graph* initGraph(int numVertex) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertex = numVertex;
    graph->adjList = (Node**)malloc(numVertex * sizeof(Node*));
    for (int i = 0; i < numVertex; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void freeGraph(Graph* graph) {
    if (graph == NULL) return;

    for (int i = 0; i < graph->numVertex; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);
}

Node* createNode(int vertex, long int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void insertEdge(Graph* graph, int vertex1, int vertex2, long int weight) {
    if (vertex1 < 0 || vertex1 >= graph->numVertex ||
        vertex2 < 0 || vertex2 >= graph->numVertex ||
        weight < 0) {
        if (prenos == 0) {
            printf("insert %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\ninsert %d %d failed", vertex1, vertex2);
        }
        return;
    }
    if (vertex1 == vertex2) {
        if (prenos == 0) {
            printf("insert %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\ninsert %d %d failed", vertex1, vertex2);
        }        return;
    }
    Node* current = graph->adjList[vertex1];
    while (current != NULL) {
        if (current->vertex == vertex2) {
            if (prenos == 0) {
                printf("insert %d %d failed", vertex1, vertex2);
                prenos = 1;
            } else {
                printf("\ninsert %d %d failed", vertex1, vertex2);
            }
            return;
        }
        current = current->next;
    }

    Node* newNode1 = createNode(vertex2, weight);
    newNode1->next = graph->adjList[vertex1];
    graph->adjList[vertex1] = newNode1;

    Node* newNode2 = createNode(vertex1, weight);
    newNode2->next = graph->adjList[vertex2];
    graph->adjList[vertex2] = newNode2;
}

void deleteEdge(Graph* graph, int vertex1, int vertex2) {
    if (vertex1 < 0 || vertex1 >= graph->numVertex || vertex2 < 0 || vertex2 >= graph->numVertex) {
        if (prenos == 0) {
            printf("delete %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\ndelete %d %d failed", vertex1, vertex2);
        }
        return;
    }
    if (vertex1 == vertex2) {
        if (prenos == 0) {
            printf("delete %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\ndelete %d %d failed", vertex1, vertex2);
        }        return;
    }
    Node* current = graph->adjList[vertex1];
    Node* prev = NULL;
    while (current != NULL && current->vertex != vertex2) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        if (prenos == 0) {
            printf("delete %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\ndelete %d %d failed", vertex1, vertex2);
        }
        return;
    }
    if (prev != NULL) {
        prev->next = current->next;
    } else {
        graph->adjList[vertex1] = current->next;
    }
    free(current);

    current = graph->adjList[vertex2];
    prev = NULL;
    while (current != NULL && current->vertex != vertex1) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        if (prenos == 0) {
            printf("delete %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\ndelete %d %d failed", vertex1, vertex2);
        }
        return;
    }
    if (prev != NULL) {
        prev->next = current->next;
    } else {
        graph->adjList[vertex2] = current->next;
    }
    free(current);
}

void updateEdge(Graph* graph, int vertex1, int vertex2, long int weight) {
    if (vertex1 < 0 || vertex1 >= graph->numVertex ||
        vertex2 < 0 || vertex2 >= graph->numVertex) {
        if (prenos == 0) {
            printf("update %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\nupdate %d %d failed", vertex1, vertex2);
        }
        return;
    }

    if (vertex1 == vertex2) {
        if (prenos == 0) {
            printf("update %d %d failed", vertex1, vertex2);
            prenos = 1;
        } else {
            printf("\nupdate %d %d failed", vertex1, vertex2);
        }        return;
    }

    Node* current = graph->adjList[vertex1];
    while (current != NULL) {
        if (current->vertex == vertex2) {
            long int new_weight = current->weight + weight;
            if (new_weight < 0) {
                if (prenos == 0) {
                    printf("update %d %d failed", vertex1, vertex2);
                    prenos = 1;
                } else {
                    printf("\nupdate %d %d failed", vertex1, vertex2);
                }                return;
            }
            current->weight = new_weight;
            break;
        }
        current = current->next;
    }

    current = graph->adjList[vertex2];
    while (current != NULL) {
        if (current->vertex == vertex1) {
            long int new_weight = current->weight + weight;
            if (new_weight < 0) {
                if (prenos == 0) {
                    printf("update %d %d failed", vertex1, vertex2);
                    prenos = 1;
                } else {
                    printf("\nupdate %d %d failed", vertex1, vertex2);
                }
                return;
            }
            current->weight = new_weight;
            return;
        }
        current = current->next;
    }
    if (prenos == 0) {
        printf("update %d %d failed", vertex1, vertex2);
        prenos = 1;
    } else {
        printf("\nupdate %d %d failed", vertex1, vertex2);
    }
}
void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}
int partition(Pair arr[], int low, int high) {
    Pair pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (comparePairs(&arr[j], &pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void Myquick(Pair arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        Myquick(arr, low, pi - 1);
        Myquick(arr, pi + 1, high);
    }
}

void primMST(Graph* graph, int start_vertex) {
    if (start_vertex < 0 || start_vertex >= graph->numVertex) {
        if (prenos == 0) {
            printf("search %d failed", start_vertex);
            prenos = 1;
        } else {
            printf("\nsearch %d failed", start_vertex);
        }
        return;
    }
    if (graph->adjList[start_vertex] == NULL) {
        if (prenos == 0) {
            printf("search %d failed", start_vertex);
            prenos = 1;
        } else {
            printf("\nsearch %d failed", start_vertex);
        }
        return;
    }
    int parent[graph->numVertex];
    int key[graph->numVertex];
    int mstSet[graph->numVertex];

    for (int i = 0; i < graph->numVertex; i++) {
        key[i] = INFINITY_VALUE;
        mstSet[i] = 0;
        parent[i] = UNDEFINED_VALUE;
    }

    key[start_vertex] = 0;

    Pair pairs[graph->numVertex];
    int pairCount = 0;

    for (int count = 0; count < graph->numVertex - 1; count++) {
        int min = INFINITY_VALUE, min_index = -1;
        for (int v = 0; v < graph->numVertex; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        if (min_index == -1)
            break;

        int u = min_index;
        mstSet[u] = 1;

        int edgeCount = 0;
        Node* pCrawl = graph->adjList[u];
        while (pCrawl != NULL) {
            int v = pCrawl->vertex;
            if (!mstSet[v] && pCrawl->weight < key[v]) {
                parent[v] = u;
                key[v] = pCrawl->weight;
                edgeCount++;
            }
            pCrawl = pCrawl->next;
        }
    }

    long int totalweight = 0;
    for (int i = 0; i < graph->numVertex; ++i) {
        if (parent[i] != UNDEFINED_VALUE) {
            pairs[pairCount].first = (i > parent[i] ? parent[i] : i);
            pairs[pairCount].second = (i < parent[i] ? parent[i] : i);
            pairCount++;
            totalweight += key[i];
        }
    }

    Myquick(pairs, 0, pairCount - 1);

    if (prenos == 0) {
        printf("%lu: [", totalweight);
        prenos = 1;
    } else {
        printf("\n%lu: [", totalweight);
    }
    int hasNextVertex = 0;
    for (int i = 0; i < pairCount; ++i) {
        if (hasNextVertex) {
            printf(", ");
        }
        printf("(%d, %d)", pairs[i].first, pairs[i].second);
        hasNextVertex = 1;
    }
    printf("]");

}

int main() {
    int maxVertex;
    scanf("%d", &maxVertex);
    Graph* graph = initGraph(maxVertex);

    char line[50];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        scanf("%[^\n]", line);

        int vertex1, vertex2;
        long int weight;
        switch (line[0]) {
            case '(':
                sscanf(line, "(%d,%d,%ld)", &vertex1, &vertex2, &weight);
                insertEdge(graph, vertex1, vertex2, weight);
                break;
            case 'i':
                sscanf(line, "i %d %d %ld", &vertex1, &vertex2, &weight);
                insertEdge(graph, vertex1, vertex2, weight);
                break;
            case 'd':
                sscanf(line, "d %d %d", &vertex1, &vertex2);
                deleteEdge(graph, vertex1, vertex2);
                break;
            case 'u':
                sscanf(line, "u %d %d %ld", &vertex1, &vertex2,&weight);
                updateEdge(graph, vertex1, vertex2,weight);
                break;
            case 's':
                sscanf(line, "s %d", &vertex1);
                primMST(graph,vertex1);
                break;
            default:
                freeGraph(graph);
                return 1;
        }
    }
    freeGraph(graph);
    return 0;
}