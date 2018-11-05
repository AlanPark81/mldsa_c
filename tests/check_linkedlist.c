#include <config.h>
#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "linkedlist.h"

LinkedList *linkedList;

void setup(void)
{
    linkedList = CreateLinkedList(sizeof(uint32_t));
}

void teardown(void)
{
    DestroyLinkedList(linkedList);
}

START_TEST(test_LinkedList_Empty)
{
    uint32_t data;
    ck_assert(!Front(linkedList, &data, sizeof(data))) ;
}
END_TEST

START_TEST(test_LinkedList_PushFront)
{
    uint32_t data = 5;
    PushFront(linkedList, &data);
    data = 3;
    ck_assert(Front(linkedList, &data, sizeof(data)));
    ck_assert(data == 5);
}
END_TEST

START_TEST(test_LinkedList_PushBack)
{
    uint32_t data = 5;
    PushBack(linkedList, &data);
    data = 3;
    ck_assert(Back(linkedList, &data, sizeof(data)));
    ck_assert(data == 5);
}
END_TEST

Suite * linkedlist_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("LinkedList");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_LinkedList_Empty);
    suite_add_tcase(s, tc_core);

    /* Limits test case */
    tc_limits = tcase_create("Limits");

    tcase_add_test(tc_limits, test_LinkedList_PushFront);
    tcase_add_test(tc_limits, test_LinkedList_PushBack);
    suite_add_tcase(s, tc_limits);

    return s;
}


