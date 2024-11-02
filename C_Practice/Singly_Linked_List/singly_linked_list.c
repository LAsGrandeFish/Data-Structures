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
    Node* new_node = create_node(data);
    if (sll->size == 0) {
        sll->head = new_node;
    } else {
        set_next(sll->tail, new_node);
    }
    sll->tail = new_node;
    sll->size++; 
}

void add_to_front(SinglyLinkedList* sll, int data) {
    Node* new_node = create_node(data);
    if (sll->size == 0) {
        sll->tail = new_node;
    } else {
        set_next(new_node, sll->head);
    }
    sll->head = new_node;
    sll->size++;
}

void insert_after_node(SinglyLinkedList* sll, int pre_node_data, int data) {
    Node* curr = sll->head;
    while (curr != NULL) {
        if (curr->data == pre_node_data) {
            Node* new_node = create_node(data);
            set_next(new_node, get_next(curr));
            set_next(curr, new_node);
            sll->size++;
        }
        curr = get_next(curr);  
    }
}

void delete_node(SinglyLinkedList* sll, int data) {
    if (sll->head->data == data) {
        sll->head = get_next(sll->head);
        sll->size--;
    }
    Node* prev = sll->head;
    Node* curr = get_next(sll->head);
    while (curr != NULL) {
        if (curr->data == data) {
            set_next(prev, get_next(curr));
            sll->size--;
            return;
        }
        curr = get_next(curr);
    }
}

void delete_node_at_position(SinglyLinkedList* sll, int position) {
    if (position == 0) {
        sll->head = get_next(sll->head);
        sll->size--;
    }
    Node* prev = sll->head;
    Node* curr = get_next(sll->head);
    int curr_idx = 1;
    while (curr != NULL) {
        if (position == curr_idx) {
            set_next(prev, get_next(curr));
            sll->size--;
            return;
        }
        curr = get_next(curr);
        curr_idx++;
    }
}

int search(SinglyLinkedList* sll, int key) {
    Node* curr = sll->head; 
    while (curr != NULL) {
        if (curr->data == key) {
            return 1;
        }
        curr = get_next(curr);
    }
    return 0;
}

void reverse(SinglyLinkedList* sll) {
    if (get_size(sll) == 1) {
        return;
    } else if (get_size(sll) == 2) {
        set_next(sll->tail, sll->head);
        set_next(sll->head, NULL);

        sll->head = sll->tail;
        sll->tail = get_next(sll->tail);
        return;
    } else {
        Node* prev = NULL;
        Node* curr = sll->head;
        Node* next = get_next(curr);

        while (next != NULL) {
            set_next(curr, prev);
            prev = curr;
            curr = next;
            next = get_next(next); 
        }
        // at this point curr = sll->tail
        set_next(curr, prev);
        sll->tail = sll->head;
        sll->head = curr;
    }
}

int* display(SinglyLinkedList* sll) {
    if (sll->size == 0) {   
        int* array = (int*)malloc(sizeof(NULL));    
        return array;
    }
    int* array = (int*)malloc(get_size(sll) * sizeof(int));
    Node* curr = get_head(sll);
    int index = 0;
    while (curr != NULL) {
        array[index] = curr->data;
        // printf("%d, ", curr->data);
        curr = get_next(curr);
        index++;
    }
    return array;
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
