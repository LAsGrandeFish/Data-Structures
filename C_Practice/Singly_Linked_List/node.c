#include <stdio.h>
#include <stdlib.h>
#include "node.h" 

// Function to initialize a new Node with data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next_node = NULL;
    return new_node;
}

// Function to get the data from a Node
int get_data(Node* node) {
    return node->data;
}

// Function to get the next node pointer
Node* get_next(Node* node) {
    return node->next_node;
}

// Function to set the next node pointer
void set_next(Node* node, Node* next_node) {
    node->next_node = next_node;
}
