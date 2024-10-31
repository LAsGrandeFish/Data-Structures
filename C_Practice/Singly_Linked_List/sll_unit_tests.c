#include <stdio.h>
#include <stdlib.h>
#include "..\Unity-master\src\unity.h"
#include "singly_linked_list.h"

void setUp(void)
{
    // setUp function can contain anything you would like to run before each test
}

void tearDown(void)
{
    // tearDown function can contain anything you would like to run after each test
}

void test_sll_is_empty(void) 
{
    SinglyLinkedList* sll_zero = create_singly_linked_list();
    TEST_ASSERT_TRUE(is_empty(sll_zero));
}

void test_sll_add_to_back(void)
{
    SinglyLinkedList* sll = create_singly_linked_list();
    add_to_back(sll, 10);
    add_to_back(sll, 11);
    TEST_ASSERT_EQUAL_INT(2, get_size(sll));
    TEST_ASSERT_EQUAL_INT(11, get_tail(sll)->data);
}

void test_sll_add_to_front(void) {
    SinglyLinkedList* sll = create_singly_linked_list();
    add_to_front(sll, 10);
    add_to_front(sll, 11);
    TEST_ASSERT_EQUAL_INT(2, get_size(sll));
    TEST_ASSERT_EQUAL_INT(11, get_head(sll)->data);
}

void test_sll_display(void) { // can be used to debug other methods
    SinglyLinkedList* sll = create_singly_linked_list();
    add_to_front(sll, 3);
    add_to_back(sll, 9);
    add_to_front(sll, 1);
    add_to_back(sll, 5);

    int* element_array = display(sll);
    int expected_array[4] = {1, 3, 9, 5};
    
    for (int i = 0; i < get_size(sll); i++) {
        TEST_ASSERT_EQUAL_INT(expected_array[i], element_array[i]);
    }
}

void test_sll_insert_after_node(void) {
    SinglyLinkedList* sll = create_singly_linked_list();
    add_to_front(sll, 1);
    add_to_back(sll, 2);
    add_to_back(sll, 3);
    add_to_back(sll, 4);
    insert_after_node(sll, 3, 8);

    int* data_array = display(sll);
    TEST_ASSERT_EQUAL_INT(8, data_array[3]);
}

void test_sll_get_head(void) {
    SinglyLinkedList* sll = create_singly_linked_list();
    Node* node_1 = create_node(12);
    sll->head = node_1;
    sll->tail = node_1;
    TEST_ASSERT_EQUAL_PTR(node_1, get_head(sll));
}

void test_sll_get_tail(void) {
    SinglyLinkedList* sll = create_singly_linked_list();
    Node* node_1 = create_node(12);
    sll->head = node_1;
    sll->tail = node_1;
    TEST_ASSERT_EQUAL_PTR(node_1, get_tail(sll));
}

void test_sll_get_size(void) {
    SinglyLinkedList* sll_zero = create_singly_linked_list();
    TEST_ASSERT_EQUAL_INT(0, get_size(sll_zero));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sll_is_empty); // 1
    RUN_TEST(test_sll_add_to_back);
    RUN_TEST(test_sll_add_to_front); // 3
    RUN_TEST(test_sll_display);
    RUN_TEST(test_sll_insert_after_node); // 5 

    RUN_TEST(test_sll_get_head);
    RUN_TEST(test_sll_get_tail);
    RUN_TEST(test_sll_get_size);
    printf(">>> compiled and ran successfully");
    return UNITY_END();
}