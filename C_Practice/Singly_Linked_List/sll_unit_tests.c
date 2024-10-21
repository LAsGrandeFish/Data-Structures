#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\ivanz\OneDrive\Studious_Foo\C_Practice\Unity-master\src\unity.h"
#include "C:\Users\ivanz\OneDrive\Studious_Foo\C_Practice\Unity-master\src\unity.c"

#include "singly_linked_list.c"

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sll_is_empty);
    printf("this ran");
    return UNITY_END();
}