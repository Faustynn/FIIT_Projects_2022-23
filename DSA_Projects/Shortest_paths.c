/*
Your task is to construct an undirected graph without loops based on the list of edges given in the input and then perform the following operations on this graph according to the input:
i - insert - inserting a new edge into the graph
s - search - search for the shortest path in the graph according to the specified start and end
u - update - modification of an existing edge in the graph (i.e. modification of the weight of the given edge), while the weight of the edge must not be changed to a negative number
d - delete - remove an existing edge from the graph

An edge is defined as a pair of two vertices, while the vertices are numbered with non-negative whole numbers from 0 to N, where N is the maximum number of vertices in the given graph.

If the given operation fails, the error message " failed" is written in a separate line.
The failure is, for example, when we try to add an edge that already exists, or when the search operation did not find any path for a given pair of vertices.

The input of the program is the number N (max. number of vertices in the graph) followed by a space and the number M (number of edges in the initial graph) on the first line.
There are M lines, where in each line there is one edge of the initial graph, in the format "(vertex_1, vertex2, weight)".
This initial graph is followed by any number of lines, each line representing one command for one operation (ie, insert, search, update, or delete).
The operation is expressed by the initial letter, i.e. i, s, u or d. The following are the data required for the given operation.
The insert operation needs the following 3 data: vertex_1 number, vertex_2 number, edge weight (also an integer)
The search operation needs the following 2 data: the number of the starting vertex, the number of the end (target) vertex
The update operation needs the following 3 data: number of vertex_1, number of vertex_2, change of edge weight (also an integer)
The delete operation needs the following 2 data: vertex_1 number, vertex_2 number

The output is the shortest paths found by search operations, while the output format is as follows:
: [vertex1, vertex2, vertex3, ..., last_vertex]
In addition, the above-mentioned error messages are also output in case of operation failure, together with the edge above which the given operation failed.


Ukážkový vstup
10 30
(5, 0, 116)
(5, 9, 163)
(5, 2, 117)
(5, 3, 110)
(5, 7, 169)
(5, 8, 188)
(0, 8, 200)
(0, 4, 113)
(0, 1, 110)
(0, 3, 129)
(0, 6, 101)
(8, 9, 160)
(8, 1, 101)
(8, 2, 146)
(8, 4, 139)
(1, 2, 159)
(1, 7, 145)
(1, 3, 182)
(1, 9, 137)
(2, 7, 184)
(2, 9, 184)
(2, 3, 176)
(2, 6, 133)
(2, 4, 199)
(7, 6, 118)
(7, 3, 172)
(9, 4, 145)
(9, 3, 180)
(4, 3, 148)
(3, 6, 129)
s 3 8
s 5 3
s 3 0
s 4 6
d 4 3
i 4 7 90
s 6 9
s 9 5
s 2 1
s 5 2
u 2 7 56
s 1 2
s 6 9
s 9 3
u 5 0 52
d 1 7
i 1 5 85
d 7 3
d 3 6
i 8 3 47
i 0 7 78
s 4 3
s 5 4
u 8 3 -3
u 2 4 -26
d 5 0
u 5 7 -42
d 8 2
u 0 6 -57
d 0 8
u 2 6 91
d 5 8
u 0 6 42
u 8 1 -53
s 4 9
u 8 9 -39
s 1 4
s 0 5
u 7 4 -51
s 1 5
s 5 7
s 6 4
u 9 4 31
u 2 3 4
s 9 7
u 9 4 -96
i 6 4 82
i 2 8 75
d 0 1
d 1 9
i 6 8 1
i 6 5 78
i 1 6 53
s 2 7
i 7 8 34
s 9 5
s 8 9
u 8 4 -65
s 3 6
d 5 3
s 1 5
u 5 9 -25
u 8 6 -100
s 8 9
s 5 2
u 2 4 19
s 7 1
s 6 7
u 0 3 -28
s 3 1
s 0 3
s 7 6
s 8 2
u 5 9 -78
s 3 6
s 3 7
s 5 0
s 4 9
s 3 4
s 2 3
u 5 9 -37
s 9 6
s 6 7
u 9 3 -13
u 8 7 63
s 7 5
d 5 2
d 1 3
u 7 5 -89
s 6 0
d 5 9
s 0 5
s 0 9
d 5 1
d 8 4
s 8 0
s 6 8
d 7 6
u 9 3 -57
u 2 3 -49
d 0 4
s 3 2
u 8 3 -75
i 7 6 25
d 2 9
s 4 3
s 9 1
u 2 7 53
s 8 3
d 8 6
u 8 3 -2
s 5 3
s 7 5
i 5 2 44
d 1 2
s 5 7
u 0 3 42
u 5 6 56
u 2 6 17
s 9 6

Ukážkový výstup
283: [3, 1, 8]
110: [5, 3]
129: [3, 0]
214: [4, 0, 6]
309: [6, 3, 9]
163: [9, 5]
159: [2, 1]
117: [5, 2]
159: [1, 2]
309: [6, 3, 9]
180: [9, 3]
186: [4, 8, 3]
259: [5, 7, 4]
145: [4, 9]
187: [1, 8, 4]
195: [0, 1, 5]
85: [1, 5]
127: [5, 7]
157: [6, 7, 4]
215: [9, 4, 7]
194: [2, 8, 6, 7]
163: [9, 5]
121: [8, 9]
45: [3, 8, 6]
85: [1, 5]
update 8 6 failed
121: [8, 9]
117: [5, 2]
82: [7, 8, 1]
35: [6, 8, 7]
92: [3, 8, 1]
101: [0, 3]
35: [7, 8, 6]
75: [8, 2]
45: [3, 8, 6]
78: [3, 8, 7]
164: [5, 6, 0]
80: [4, 9]
117: [3, 8, 7, 4]
119: [2, 8, 3]
101: [9, 5, 6]
35: [6, 8, 7]
127: [7, 5]
86: [6, 0]
116: [0, 7, 5]
193: [0, 4, 9]
87: [8, 6, 0]
1: [6, 8]
119: [3, 8, 2]
update 8 3 failed
109: [4, 7, 6, 8, 3]
169: [9, 8, 1]
44: [8, 3]
177: [5, 7, 8, 3]
38: [7, 5]
38: [5, 7]
144: [9, 4, 7, 6]

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
typedef unsigned short int usi;
#define INT_MAX ((1 << sizeof(usi) * 8) - 1)
#define USI_MAX ((usi)-1)
usi prenos = 0;


typedef struct Edge {
    usi vertex;
    usi weight;
    struct Edge* next;
} Edge;
typedef struct {
    usi vertices;
    Edge* edges;
    int * prev_vertices;
} Graph;
Graph createGraph(usi vertices) {
    Graph graph;
    graph.vertices = vertices;
    graph.edges = (Edge*)malloc(vertices * sizeof(Edge));
    graph.prev_vertices = (int*)malloc(vertices * sizeof(int));
    for (size_t i = 0; i < vertices; i++) {
        graph.edges[i].next = NULL;
        graph.prev_vertices[i] = -1;
    }
    return graph;
}
void errorPrint(int k,usi src,usi dest){
    if(k==1){
        if (prenos == 0) {
            printf("insert %hu %hu failed", src, dest);
            prenos = 1;
        } else {
            printf("\ninsert %hu %hu failed", src, dest);
        }
    }else if(k==2){
        if (prenos == 0) {
            printf("delete %hu %hu failed", src, dest);
            prenos = 1;
        } else {
            printf("\ndelete %hu %hu failed", src, dest);
        }
    }else if(k==3){
        if (prenos == 0) {
            printf("update %hu %hu failed", src, dest);
            prenos = 1;
        } else {
            printf("\nupdate %hu %hu failed", src, dest);
        }
    }else if(k==4){
        if (prenos == 0) {
            printf("search failed");
            prenos = 1;
        } else {
            printf("\nsearch failed");
        }
    }
}

void heapify(Edge* arr[], size_t n, size_t i) {
    size_t largest = i;
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;

    if (l < n && arr[l]->weight > arr[largest]->weight)
        largest = l;
    if (r < n && arr[r]->weight > arr[largest]->weight)
        largest = r;

    if (largest != i) {
        Edge* temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}
void heapSort(Edge* arr[], size_t n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        Edge* temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}
void sortEdges(Graph* graph) {
    if (graph == NULL || graph->edges == NULL)
        return;

    Edge* curr_edge = graph->edges;
    size_t num_edges = 0;

    while (curr_edge != NULL) {
        num_edges++;
        curr_edge = curr_edge->next;
    }

    Edge* edge_arr[num_edges];
    curr_edge = graph->edges;
    size_t i = 0;
    while (curr_edge != NULL) {
        edge_arr[i] = curr_edge;
        curr_edge = curr_edge->next;
        i++;
    }
    heapSort(edge_arr, num_edges);
}


usi minDistance(const usi dist[], const usi visited[], const usi edges[], usi vertices) {
    usi min = INT_MAX, min_index = -1;
    usi min_edges = INT_MAX;

    for (usi v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            if (dist[v] < min || edges[v] < min_edges) {
                min = dist[v];
                min_edges = edges[v];
                min_index = v;
            }
        }
    }

    return min_index;
}
void dijkstra(Graph* graph, usi src, usi dest, int* totalweight) {
    usi dist[MAX_VERTICES];
    usi visited[MAX_VERTICES];
    usi edges[MAX_VERTICES];

    for (usi i = 0; i < graph->vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        edges[i] = 0; // Initialize edges to 0
        graph->prev_vertices[i] = USI_MAX;
    }

    dist[src] = 0;

    for (usi count = 0; count < graph->vertices; count++) {
        usi u = minDistance(dist, visited, edges, graph->vertices);
        if (u == USI_MAX || u == dest)
            break;
        visited[u] = 1;

        Edge* edge = graph->edges[u].next;
        while (edge != NULL) {
            usi v = edge->vertex;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + edge->weight < dist[v]) {
                dist[v] = dist[u] + edge->weight;
                edges[v] = edges[u] + 1; // Increment edges for v
                graph->prev_vertices[v] = u;
            }
            usi reverseEdge = u;
            if (edge->next != NULL && edge->next->vertex == reverseEdge) {
                reverseEdge = v;
                if (!visited[reverseEdge] && dist[v] != INT_MAX && dist[v] + edge->weight < dist[reverseEdge]) {
                    dist[reverseEdge] = dist[v] + edge->weight;
                    edges[reverseEdge] = edges[v] + 1; // Increment edges for reverseEdge
                    graph->prev_vertices[reverseEdge] = v;
                }
            }
            edge = edge->next;
        }
    }

    *totalweight = dist[dest];
}
usi search(Graph* graph, usi src, usi dest) {
    int totalweight = 0;
    if (src == dest || src < 0 || src >= MAX_VERTICES || dest < 0 || dest >= MAX_VERTICES) {
        errorPrint(4, src, dest);
        return 0;
    }

    dijkstra(graph, src, dest,&totalweight);
    if (graph->prev_vertices[dest] == -1) {
        errorPrint(4, src, dest);
        return 0;
    }

    usi path[MAX_VERTICES];
    int path_length = 0;

    usi current_vertex = dest;
    while (current_vertex != src) {
        usi prev_vertex = graph->prev_vertices[current_vertex];
        path[path_length++] = current_vertex;
        current_vertex = prev_vertex;
    }
    path[path_length++] = src;

    if (prenos == 0) {
        printf("%d: ", totalweight);
        prenos = 1;
    } else {
        printf("\n%d: ", totalweight);
    }

    for (int i = path_length - 1; i >= 0; i--) {
        if (i == path_length - 1) {
            printf("[%hu, ", path[i]);
        } else if (i == 0) {
            printf("%hu]", path[i]);
        } else {
            printf("%hu, ", path[i]);
        }
    }
    return totalweight;
}

void insert_Edge(Graph* graph, usi src, usi dest, usi weight) {
    if (src == dest) {
        errorPrint(1, src, dest);
        return;
    }
    if (src >= graph->vertices || dest >= graph->vertices) {
        errorPrint(1, src, dest);
        return;
    }

    Edge* current = &graph->edges[src];
    while (current->next != NULL) {
        if (current->next->vertex == dest) {
            errorPrint(1, src, dest);
            return;
        }
        current = current->next;
    }

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->vertex = dest;
    newEdge->weight = weight;
    newEdge->next = NULL;
    current->next = newEdge;

    current = &graph->edges[dest];
    while (current->next != NULL) {
        if (current->next->vertex == src) {
            errorPrint(1, src, dest);
            return;
        }
        current = current->next;
    }

    Edge* reverseEdge = (Edge*)malloc(sizeof(Edge));
    reverseEdge->vertex = src;
    reverseEdge->weight = weight;
    reverseEdge->next = NULL;

    current->next = reverseEdge;

    sortEdges(graph);
}
void deleteEdge(Graph* graph, usi src, usi dest) {
    if (src == dest) {
        errorPrint(2, src, dest);
        return;
    }
    if (src >= graph->vertices || dest >= graph->vertices) {
        errorPrint(2, src, dest);
        return;
    }

    Edge* current = &graph->edges[src];
    while (current->next != NULL) {
        if (current->next->vertex == dest) {
            Edge* temp = current->next;
            current->next = temp->next;
            free(temp);
            break;
        }
        current = current->next;
    }

    current = &graph->edges[dest];
    while (current->next != NULL) {
        if (current->next->vertex == src) {
            Edge* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
    errorPrint(2, src, dest);
}
void update(Graph* graph, usi src, usi dest, int distance) {
    if (src == dest || src >= graph->vertices || src < 0 || dest >= graph->vertices || dest < 0) {
        errorPrint(3, src, dest);
        return;
    }

    Edge* current_edge = graph->edges[src].next;
    while (current_edge) {
        if (current_edge->vertex == dest) {
            int new_weight = current_edge->weight + distance;
            if (new_weight > 0) {
                current_edge->weight = new_weight;
            } else {
                errorPrint(3, src, dest);
                return;
            }
            break;
        }
        current_edge = current_edge->next;
    }

    current_edge = graph->edges[dest].next;
    while (current_edge) {
        if (current_edge->vertex == src) {
            int new_weight = current_edge->weight + distance;
            if (new_weight > 0) {
                current_edge->weight = new_weight;
            } else {
                errorPrint(3, src, dest);
                return;
            }
            return;
        }
        current_edge = current_edge->next;
    }
    errorPrint(3, src, dest);
}


void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Edge* current_edge = graph->edges[i].next;
        while (current_edge) {
            Edge* temp = current_edge;
            current_edge = current_edge->next;
            free(temp);
        }
    }
    free(graph->prev_vertices);
    free(graph->edges);
}
void printGraph(const Graph* graph) {
    printf("Graph:\n");
    for (usi i = 0; i < graph->vertices; ++i) {
        printf("Vertex %hu:", i);
        Edge* current_edge = graph->edges[i].next;
        while (current_edge) {
            printf(" -> %hu(weight:%hu)", current_edge->vertex, current_edge->weight);
            current_edge = current_edge->next;
        }
        printf("\n");
    }
}
int main() {
    usi N, M;
    usi vertex1, vertex2;
    int distance;
    scanf("%hu %hu\n", &N, &M);
    Graph graph = createGraph(N);

    for (int i = 0; i < M; i++) {
        char c;
        scanf("%c%hu, %hu, %d%c\n", &c, &vertex1, &vertex2, &distance, &c);
        insert_Edge(&graph, vertex1, vertex2, distance);
    }

    char line[50];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        char c;
        sscanf(line, "%c", &c);

        switch (c) {
            case 'i': // insert
                sscanf(line, "%*c %hu %hu %d", &vertex1, &vertex2, &distance);
                insert_Edge(&graph, vertex1, vertex2, distance);
                break;
            case 's': // search
                sscanf(line, "%*c %hu %hu", &vertex1, &vertex2);
                search(&graph, vertex1, vertex2);
                break;
            case 'u': // update
                sscanf(line, "%*c %hu %hu %d", &vertex1, &vertex2, &distance);
                update(&graph, vertex1, vertex2, distance);
                break;
            case 'd': // delete
                sscanf(line, "%*c %hu %hu", &vertex1, &vertex2);
                deleteEdge(&graph, vertex1, vertex2);
                break;
            default:
                return 1;
        }
    }
    freeGraph(&graph);
    return 0;
}