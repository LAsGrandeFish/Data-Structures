#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct SinglyLinkedList 
{
    struct Node* head;
    struct Node* tail;
    int size;
} SinglyLinkedList;

SinglyLinkedList* create_singly_linked_list();

int is_empty(SinglyLinkedList* sll);
void add_to_back(SinglyLinkedList* sll, int data);
void add_to_front(SinglyLinkedList* sll, int data);
void insert_after_node(SinglyLinkedList* sll, int prev_node_data, int data);
void delete_node(SinglyLinkedList* sll, int data);
void delete_node_at_position(SinglyLinkedList* sll, int position);
int search(SinglyLinkedList* sll, int key);
int* display(SinglyLinkedList* sll);
void reverse(SinglyLinkedList* sll);

Node* get_head(SinglyLinkedList* sll);
Node* get_tail(SinglyLinkedList* sll);
int get_size(SinglyLinkedList* sll);

#endif // SINGLY_LINKED_LIST_H