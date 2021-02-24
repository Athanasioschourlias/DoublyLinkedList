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

/*Because we are creating this liked list so that can work with generic data types we can not implement a print function*/

void put(struct Node** head_ref,struct Node**  tail_ref, void *new_data, size_t data_size,int* size);

void putIn(struct Node** head_ref,struct Node**  tail_ref, void *new_data, size_t data_size,int pos,int* size);

void removeNode(struct Node** head_ref,struct Node**  tail_ref, int *size);

void  removeNodeFrom(struct Node** head_ref,struct Node**  tail_ref, int pos, int *size);

#endif //LINKEDLIST_C_DOUBLYLINKEDLIST_H
