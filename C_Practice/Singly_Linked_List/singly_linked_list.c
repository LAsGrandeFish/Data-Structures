#include <stdio.h> // includes printf
#include <stdlib.h>
#include "singly_linked_list.h"
#include "node.h"

SinglyLinkedList* create_singly_linked_list()
{
    SinglyLinkedList* sll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (sll == NULL)
    {
        printf("Memory allocation for singly linked list fail");
        exit(1);
    }
    sll->head = NULL;
    sll->tail = NULL;
    sll->size = 0;
    return sll;
}

int is_empty(SinglyLinkedList* sll)
{
    return sll->size == 0;
}
