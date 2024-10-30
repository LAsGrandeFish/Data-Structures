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
    TEST_ASSERT_EQUAL_INT(get_size(sll), 2);
    TEST_ASSERT_EQUAL_INT(get_tail(sll)->data, 11);
}

void test_sll_add_to_front(void) {
    SinglyLinkedList* sll = create_singly_linked_list();
    add_to_front(sll, 10);
    add_to_front(sll, 11);
    TEST_ASSERT_EQUAL_INT(get_size(sll), 2);
    TEST_ASSERT_EQUAL_INT(get_head(sll)->data, 11);
}

// void test_sll_display(void) {
//     SinglyLinkedList* sll = create_singly_linked_list();
//     add_to_front(3);
//     add_to_back(9);
//     add_to_front(1);
//     add_to_back(5);

// }

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
    TEST_ASSERT_EQUAL_INT(get_size(sll_zero), 0);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sll_is_empty);
    RUN_TEST(test_sll_add_to_back);
    RUN_TEST(test_sll_add_to_front);

    RUN_TEST(test_sll_get_head);
    RUN_TEST(test_sll_get_tail);
    RUN_TEST(test_sll_get_size);
    printf(">>> compiled and ran successfully");
    return UNITY_END();
}