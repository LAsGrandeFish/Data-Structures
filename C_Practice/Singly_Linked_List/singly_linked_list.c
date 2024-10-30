#include <stdio.h> // includes printf
#include <stdlib.h>
#include "singly_linked_list.h"
#include "node.h"

SinglyLinkedList* create_singly_linked_list() {
    SinglyLinkedList* sll = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (sll == NULL) {
        printf("Memory allocation for singly linked list fail");
        exit(1);
    }
    sll->head = NULL;
    sll->tail = NULL;
    sll->size = 0;
    return sll;
}

int is_empty(SinglyLinkedList* sll) {
    return sll->size == 0;
}

void add_to_back(SinglyLinkedList* sll, int data) {
    // if (sll == NULL || data == NULL) {
    //     exit(1);
    // }
    Node* new_node = create_node(data);
    if (sll->size == 0) {
        sll->head = new_node;
    } else {
        set_next(sll->tail, new_node);
    }
    sll->tail = new_node;
    sll->size++; 
}

Node* get_head(SinglyLinkedList* sll) {
    return sll->head;
}

Node* get_tail(SinglyLinkedList* sll) {
    return sll->tail;
}

int get_size(SinglyLinkedList* sll) {
    return sll->size;
}
