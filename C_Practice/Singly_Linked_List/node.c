#include <stdio.h>
#include <stdlib.h>

// Define the Node struct
typedef struct Node {
    int data;
    struct Node* next_node;
} Node;

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

// int main() { // alawys need a main() in c/++ - thought there some ways to do without
//     // Example usage
//     Node* node1 = create_node(10);
//     Node* node2 = create_node(20);
//     set_next(node1, node2);

//     printf("Data in node1: %d\n", get_data(node1));
//     printf("Data in node2: %d\n", get_data(node2));

//     // Free allocated memory
//     free(node1);
//     free(node2);
//     printf("we are here");

//     return 0;
// }
