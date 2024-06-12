/*
 Your task is to implement a balanced tree that will serve as an implementation of the abstract data type dynamic set. The following operations should be supported:
i - insert - inserting a new item into the tree
s - search - search for an item or an interval of items by ID or an ID interval
d - delete - removing an item from the tree by ID

Items represent people, consisting of a unique ID, first name, last name, and date of birth.

The input of the program is the individual operations above the tree, where each operation is located in a separate line.
A line always begins with the letter specifying the operation (i.e., i, s, or d), followed by the data required for that operation.
The insert operation needs all the data to insert the given item, i.e. ID, first name, last name and date of birth.
The search operation uses either only the ID of the searched item or a pair of numbers representing the ID interval.
The delete operation only uses the ID of the item to be deleted, if it exists.

The output is the items found using the search operations, while in the case of using the ID interval, these items are sorted by ID (from the smallest value to the highest).
Each item is on a separate line.

Do 20.03.2024, 18:00

Ukážkový vstup
i 6973984 Stephanie Knight 16.10.1968
i 3125122 James Mejia 14.5.1986
i 1062148 Gwendolyn Payne 21.1.1969
i 3424303 Matthew Henderson 10.7.1977
s 826456
i 9603312 Phillip Rodriguez 17.4.1973
i 6173713 Justin Roberts 18.7.1969
i 7000916 Karen Walker 6.9.1979
d 9603312
s 3125122
i 9037302 Kelly Turner 24.5.2000
s 7000916
s 6173713
i 8690778 Anne Brown 18.5.1996
i 7328095 Erica Sanchez 23.2.1965
d 3125122
s 567088 6751815
s 7328095
s 4364409 6773840
d 7000916
s 2836601 5208580
s 2190293 4023055
s 7328095
s 8690778
s 8690778
s 634692 5957094
s 9037302
s 7328095
d 7328095
s 3424303
d 9037302
s 123456

Ukážkový výstup
3125122 James Mejia 14.5.1986
7000916 Karen Walker 6.9.1979
6173713 Justin Roberts 18.7.1969
1062148 Gwendolyn Payne 21.1.1969
3424303 Matthew Henderson 10.7.1977
6173713 Justin Roberts 18.7.1969
7328095 Erica Sanchez 23.2.1965
6173713 Justin Roberts 18.7.1969
3424303 Matthew Henderson 10.7.1977
3424303 Matthew Henderson 10.7.1977
7328095 Erica Sanchez 23.2.1965
8690778 Anne Brown 18.5.1996
8690778 Anne Brown 18.5.1996
1062148 Gwendolyn Payne 21.1.1969
3424303 Matthew Henderson 10.7.1977
9037302 Kelly Turner 24.5.2000
7328095 Erica Sanchez 23.2.1965
3424303 Matthew Henderson 10.7.1977
*/



#include <stdio.h>
#include <stdlib.h>

int prenos = 0; // global value for \n
typedef struct {
    char name[16];
    char surname[16];
    char year[11];
} Data; // struct for personal data
struct BINARY_TREE {
    int id;
    Data data;
    struct BINARY_TREE *left;
    struct BINARY_TREE *right;
    int height;
}; // treee struct
typedef struct BINARY_TREE Tree;

Tree *createTree(int id, Data data) {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->id = id;
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    tree->height = 1;
    return tree;
} // create node
int heightofPoint(Tree *tree) {
    if (tree == NULL) {
        return 0;
    }
    return tree->height;
} //  calculate height
int max(int a, int b) {
    return (a > b) ? a : b;
} // defolt look max function
void updеHeight(Tree *sourse, char logic) {
    if (logic == 'l') {
        sourse->height = 1 + heightofPoint(sourse->left);
    } else if (logic == 'r') {
        sourse->height = 1 + heightofPoint(sourse->right);
    } else {
        printf("Error in und metod");
    }
} // upd height metod

Tree *rightFlip(Tree *sourse) {
    if (sourse == NULL || sourse->left == NULL) {
        return sourse;
    }
    Tree *sourceLeft = sourse->left;
    Tree *buff = sourceLeft->right;
    sourceLeft->right = sourse;
    sourse->left = buff;

    if (heightofPoint(sourse->left) > heightofPoint(sourse->right)) {
        updеHeight(sourse, 'l');
    } else {
        updеHeight(sourceLeft, 'r');
    }
    if (heightofPoint(sourceLeft->left) > heightofPoint(sourceLeft->right)) {
        updеHeight(sourceLeft, 'l');
    } else {
        updеHeight(sourceLeft, 'r');
    }
    return sourceLeft;
} //RR
Tree *leftFlip(Tree *sourse) {
    if (sourse == NULL || sourse->right == NULL) {
        return sourse;
    }
    Tree *sourceRight = sourse->right;
    Tree *buff = sourceRight->left;
    sourceRight->left = sourse;
    sourse->right = buff;

    if (heightofPoint(sourse->left) > heightofPoint(sourse->right)) {
        updеHeight(sourse, 'l');
    } else {
        updеHeight(sourse, 'r');
    }
    if (heightofPoint(sourceRight->left) > heightofPoint(sourceRight->right)) {
        updеHeight(sourceRight, 'l');
    } else {
        updеHeight(sourceRight, 'r');
    }
    return sourceRight;
} //LL
Tree *rightleftFlip(Tree *sourse) {
    if (sourse == NULL) {
        return sourse;
    }
    sourse->right = rightFlip(sourse->right);
    return leftFlip(sourse);
} //RL
Tree *leftrightFlip(Tree *sourse) {
    if (sourse == NULL) {
        return sourse;
    }
    sourse->left = leftFlip(sourse->left);
    return rightFlip(sourse);
} //LR
int bfTree(Tree *tree) {
    if (tree == NULL) {
        return 0;
    }
    return heightofPoint(tree->left) - heightofPoint(tree->right);
}

Tree *insertTree(Tree *tree, int id, Data data) {
    if (tree == NULL) {
        return createTree(id, data);
    }

    if (id < tree->id)
        tree->left = insertTree(tree->left, id, data);
    else if (id > tree->id)
        tree->right = insertTree(tree->right, id, data);
    else {
        return tree;
    }
    if (heightofPoint(tree->left) > heightofPoint(tree->right)) {
        updеHeight(tree, 'l');
    } else {
        updеHeight(tree, 'r');
    }

    int balance = bfTree(tree);
    if (balance > 1 && tree->id < tree->left->id) {
        return rightFlip(tree);
    }
    if (balance < -1 && tree->id > tree->right->id) {
        return leftFlip(tree);
    }
    if (balance > 1 && tree->id > tree->left->id) {
        return leftrightFlip(tree);
    }
    if (balance < -1 && tree->id < tree->right->id) {
        return rightleftFlip(tree);
    }
    return tree;
} // i
Tree *smallestPoint(Tree *tree) {
    Tree *buff = tree;
    while (buff->left != NULL)
        buff = buff->left;
    return buff;
} // look smallest left node
Tree *deleteFromTree(Tree *tree, int id) {
    if (tree == NULL) {
        return tree;
    }

    if (id < tree->id) {
        tree->left = deleteFromTree(tree->left, id);
    } else if (id > tree->id) {
        tree->right = deleteFromTree(tree->right, id);
    } else {
        if ((tree->left == NULL) || (tree->right == NULL)) {
            Tree *temp = tree->left ? tree->left : tree->right;

            if (temp == NULL) {
                temp = tree;
                tree = NULL;
            } else {
                *tree = *temp;
            }
            free(temp);
        } else {
            Tree *temp = smallestPoint(tree->right);
            tree->id = temp->id;
            tree->data = temp->data;
            tree->right = deleteFromTree(tree->right, temp->id);
        }
    }

    if (tree == NULL) {
        return tree;
    }

    if (heightofPoint(tree->left) > heightofPoint(tree->right)) {
        updеHeight(tree, 'l');
    } else {
        updеHeight(tree, 'r');
    }

    int balance = bfTree(tree);

    if (balance > 1 && bfTree(tree->left) >= 0) {
        return rightFlip(tree);
    }

    if (balance > 1 && bfTree(tree->left) < 0) {
        tree->left = leftFlip(tree->left);
        return rightFlip(tree);
    }

    if (balance < -1 && bfTree(tree->right) <= 0) {
        return leftFlip(tree);
    }

    if (balance < -1 && bfTree(tree->right) > 0) {
        tree->right = rightFlip(tree->right);
        return leftFlip(tree);
    }

    return tree;
} // d
Tree *dualSeartchTree(Tree *tree, int idStart, int idEnd) {
    if (tree == NULL) {
        return tree;
    }
    if (idStart > idEnd) {
        int buff = idStart;
        idStart = idEnd;
        idEnd = buff;
    }


    if (idEnd < tree->id) {
        return dualSeartchTree(tree->left, idStart, idEnd);
    } else if (idStart > tree->id) {
        return dualSeartchTree(tree->right, idStart, idEnd);
    } else {
        dualSeartchTree(tree->left, idStart, idEnd);
        if (prenos == 1) {
            printf("\n%d %s %s %s", tree->id, tree->data.name,tree->data.surname,tree->data.year);
        } else {
            prenos = 1;
            printf("%d %s %s %s", tree->id, tree->data.name,tree->data.surname,tree->data.year);
        }
        return dualSeartchTree(tree->right, idStart, idEnd);
    }
} // s id1 id2
Tree *seartchTree(Tree *tree, int id) {
    if (tree == NULL) {
        return tree;
    }

    while (tree != NULL) {
        if (tree->id < id) {
            tree = tree->right;
        } else if (tree->id == id) {
            if (prenos == 1) {
                printf("\n%d %s %s %s", tree->id, tree->data.name,tree->data.surname,tree->data.year);
            } else {
                prenos = 1;
                printf("%d %s %s %s", tree->id, tree->data.name,tree->data.surname,tree->data.year);
            }            return tree;
        } else {
            tree = tree->left;
        }
    }
    return NULL;
} // s id1

void freeTree(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
} // free all mem
int main() {
    char line[50];
    unsigned int id, id2;
    Tree *tree = NULL;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char c;
        sscanf(line, "%c", &c);
        switch (c) {
            case 'i':
                sscanf(line, "%*c %d", &id);
                Data newData;
                sscanf(line,"%*c %*d %s %s %10s", newData.name, newData.surname, newData.year);
                tree = insertTree(tree, id, newData);
                break;
            case 's':
                if (sscanf(line, "%*c %d %d", &id, &id2) == 2) {
                    dualSeartchTree(tree, id, id2);
                } else if (sscanf(line, "%*c %d", &id) == 1) {
                    seartchTree(tree, id);
                }
                break;
            case 'd':
                sscanf(line, "%*c %d", &id);
                tree = deleteFromTree(tree, id);
                break;
            default:
                printf("Error in switch case\n");
                return 1;
        }
    }
    freeTree(tree);
    return 0;
} // main