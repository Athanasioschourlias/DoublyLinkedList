#ifndef LINKEDLIST_C_DOUBLYLINKEDLIST_H
#define LINKEDLIST_C_DOUBLYLINKEDLIST_H
#define TRUE  1
#define FALSE 0


#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    // Any data type can be stored in this node
    void  *data;

    /* Storing pointers to previous and next nodes */
    struct Node *prev;
    struct Node *next;

} Node;

typedef struct listPointers {

    Node* head_ref;
    Node* tail_ref;

    int* size;

} listPointers;

/*Because we are creating this liked list so that can work with generic data types we can not implement a print function*/

void put(void *new_data, size_t data_size, struct listPointers** list_ref);

void putIn(void *new_data, size_t data_size,int pos, struct listPointers** list_ref);

void removeNode(struct listPointers** list_ref);

void  removeNodeFrom(int pos, struct listPointers** list_ref);

listPointers *createList();

#endif //LINKEDLIST_C_DOUBLYLINKEDLIST_H
