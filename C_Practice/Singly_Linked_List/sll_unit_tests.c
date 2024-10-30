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

void test_sll_get_head(void) {
    SinglyLinkedList* sll = create_singly_linked_list();
    Node* node_1 = create_node(12);
    sll->head = node_1;
    TEST_ASSERT_EQUAL_PTR(node_1, get_head(sll));
}

void test_sll_get_tail(void) {

}

void test_sll_get_size(void) {
    
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
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sll_is_empty);
    RUN_TEST(test_sll_add_to_back);
    RUN_TEST(test_sll_get_head);
    printf(">>> compiled and ran successfully");
    return UNITY_END();
}