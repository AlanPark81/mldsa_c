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
    ck_assert_ptr_ne(linkedList, NULL);
    PushFront(linkedList, &data);
    data = 3;
    ck_assert(Front(linkedList, &data, sizeof(data)));
    ck_assert_msg(data == 5, "front failed");
    data = 3;
    PopFront(linkedList, &data);
    ck_assert_msg(data == 5, "pop_front failed");

    for( uint32_t i=0 ; i < 13 ; i++) {
        PushFront(linkedList, &i);
    }

    for( uint32_t i=0 ; i < 13 ; i++) {
        uint32_t data;
        PopBack(linkedList, &data);
        ck_assert_uint_eq(data, i);
    }
}
END_TEST

START_TEST(test_LinkedList_PushBack)
{
    uint32_t data = 5;
    PushBack(linkedList, &data);
    data = 3;
    ck_assert(Back(linkedList, &data, sizeof(data)));
    ck_assert(data == 5);
    data = 3;
    PopBack(linkedList, &data);
    ck_assert(data == 5);
    for( uint32_t i=0 ; i < 13 ; i++) {
        PushBack(linkedList, &i);
    }

    for( uint32_t i=0 ; i < 13 ; i++) {
        uint32_t data;
        PopFront(linkedList, &data);
        ck_assert_uint_eq(data, i);
    }
}
END_TEST

START_TEST(test_LinkedList_Iterator)
    {
        for ( uint32_t data = 0 ; data < 13 ; data++ ) {
            PushBack(linkedList, &data);
        }
        ListIterator* iterator = GetIterator(linkedList);
        for ( uint32_t data = 0 ; data < 13 ; data++ ) {
            uint32_t curr_data=255;
            GetCurrValue(iterator, &curr_data, sizeof(curr_data));
            ck_assert_uint_eq(curr_data, data);
            Next(iterator);
        }
        free(iterator);
    }
END_TEST

Suite * linkedlist_suite(void)
{
    Suite *s;
    TCase *tc_init;
    TCase *tc_push_pop;
    TCase *tc_iterator;

    s = suite_create("LinkedList");

    /* Core test case */
    tc_init = tcase_create("Init");
    tcase_add_checked_fixture(tc_init, setup, teardown);
    tcase_add_test(tc_init, test_LinkedList_Empty);
    suite_add_tcase(s, tc_init);

    /* Limits test case */
    tc_push_pop = tcase_create("PushPop");
    tcase_add_checked_fixture(tc_push_pop, setup, teardown);
    tcase_add_test(tc_push_pop, test_LinkedList_PushFront);
    tcase_add_test(tc_push_pop, test_LinkedList_PushBack);
    suite_add_tcase(s, tc_push_pop);

    tc_iterator = tcase_create("Iterator");
    tcase_add_checked_fixture(tc_iterator, setup, teardown);
    tcase_add_test(tc_iterator, test_LinkedList_Iterator);
    suite_add_tcase(s, tc_iterator);

    return s;
}


