#include "DoublyLinkedList.h"

/* Function to add a node at the end of Doubly Linked List.
   This function expects a pointer to the data to be added
   and size of the data type. The user is responsible to allocate
   memory and create the nodes necessary for the tail and the head.*/
void put(struct Node** head_ref,struct Node**  tail_ref, void *new_data, size_t data_size, int *size)
{
    // Allocate memory for node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Here we cover both cases, when the list has only the head and nothing else and when the list it isn't empty.
    Node* curr;
    curr = (*head_ref);
    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = new_node;
    new_node->prev = curr;
    new_node->next = NULL;
    (*tail_ref) = new_node;

    //Copy contents of new_data to newly allocated memory.If this is an array of chars.
    //Assumption: char takes 1 byte.
    int i;
    for (i=0; i<data_size; i++)
        //Using the char data type as the Byte type like we have in java.
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

    //adding one to the size of the list, a pointer the user is obligated to create.
    (*size)++;
}

/*Not recommended,both performance issues and danger of entering an invalid position(A position that does not have
at the moment any node).Worst case of O(n)*/
void putIn(struct Node** head_ref,struct Node**  tail_ref, void *new_data, size_t data_size, int pos, int *size){

    // Allocate memory for node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Here we cover both cases, when the list has only the head and nothing else and when the list it isn't empty.
    Node* curr;
    Node* prev;
    curr = (*head_ref);
    prev = NULL;
    int i = 0;
    while (curr->next != NULL && i != pos){
        prev = curr;
        curr = curr->next;
        i++;
    }

    //we are checking if the user entered a valid value.
    if(curr->next == NULL && i < pos){
        printf("Sorry this position is invalid!");
        return;

    }

    new_node->prev = prev;
    prev->next = new_node;
    new_node->next = curr;
    (*tail_ref) = new_node;

    //Copy contents of new_data to newly allocated memory.If this is an array of chars.
    //Assumption: char takes 1 byte.
    for (i=0; i<data_size; i++)
        //Using the char data type as the Byte type like we have in java.
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

    (*size)++;
}

void removeNode(struct Node** head_ref,struct Node**  tail_ref, int *size){

    //We are removing from the end of the list
    Node* tmp = (*tail_ref);
    (*tail_ref) = (*tail_ref)->prev;
    (*tail_ref)->next = NULL;
    //freeing memory of the node.
    free(tmp);

    (*size)--;


}

void  removeNodeFrom(struct Node** head_ref,struct Node**  tail_ref, int pos, int *size){

    //checking for invalid input;
    if( pos < 0)
        return;

    Node* curr;
    Node* prev;
    curr = (*head_ref);
    prev = NULL;
    int i = 0;
    while (curr->next != NULL && i != pos){
        prev = curr;
        curr = curr->next;
        i++;
    }

    //we are checking if the user entered a valid value.
    if(curr->next == NULL && i != pos){
        printf("Sorry this position is invalid!");
        return;

    }

    Node* tmp = curr;
    prev->next = curr->next;
    /*We have a bidirectional linked list. So we need to update the pointer of the node which is "infront" of the one
    we are deleting*/
    curr->next->prev = prev;
    free(tmp);

    (*size)--;
}