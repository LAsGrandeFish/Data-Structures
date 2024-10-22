#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList 
{
    struct Node* head;
    struct Node* tail;
    int size;
} SinglyLinkedList;

SinglyLinkedList* create_singly_linked_list();
int is_empty(SinglyLinkedList* sll);

#endif // SINGLY_LINKED_LIST_H