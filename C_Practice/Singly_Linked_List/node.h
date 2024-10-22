#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

// Define the Node struct
typedef struct Node {
    int data;
    struct Node* next_node;
} Node;

// Function declarations
Node* create_node(int data);
int get_data(Node* node);
Node* get_next(Node* node);
void set_next(Node* node, Node* next_node);

#endif // NODE_H
