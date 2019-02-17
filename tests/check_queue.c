//
// Created by alanpark on 18. 11. 5.
//

#include <config.h>
#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "queue.h"

Queue *queue;

void setup_queue(void)
{
    queue = CreateQueue( sizeof(uint32_t) );
}

void teardown_queue(void)
{
    DestroyQueue(queue);
}

START_TEST(test_Queue_Empty)
    {
        uint32_t data;
        ck_assert(queue);
        ck_assert(!Front(queue, &data, sizeof(data))) ;
        ck_assert(!Dequeue(queue, &data, sizeof(data))) ;
    }
END_TEST

START_TEST(test_Queue_one_element)
    {
        uint32_t data;
        ck_assert(QueueEmpty(queue));
        data = 1;
        Enqueue(queue, &data);
        data = 13;
        ck_assert(Front(queue, &data, sizeof(data))) ;
        ck_assert_uint_eq(data, 1);
        data = 13;
        ck_assert(Dequeue(queue, &data, sizeof(data)));
        ck_assert_uint_eq(data, 1);
        ck_assert(QueueEmpty(queue));
    }
END_TEST

START_TEST(test_Queue_two_elements)
    {
        uint32_t data;
        ck_assert(QueueEmpty(queue));
        data = 1;
        Enqueue(queue, &data);
        data = 2;
        Enqueue(queue, &data);
        data = 13;
        ck_assert(Front(queue, &data, sizeof(data))) ;
        ck_assert_uint_eq(data, 1);
        data = 13;
        ck_assert(Dequeue(queue, &data, sizeof(data)));
        ck_assert_uint_eq(data, 1);
        data = 13;
        ck_assert(Front(queue, &data, sizeof(data))) ;
        ck_assert_uint_eq(data, 2);
        data = 13;
        ck_assert(Dequeue(queue, &data, sizeof(data)));
        ck_assert_uint_eq(data, 2);
        ck_assert(QueueEmpty(queue));
    }
END_TEST

START_TEST(test_Queue_three_elements)
    {
        uint32_t data;
        ck_assert(QueueEmpty(queue));
        data = 1;
        Enqueue(queue, &data);
        data = 2;
        Enqueue(queue, &data);
        data = 3;
        Enqueue(queue, &data);
        data = 13;
        ck_assert(Front(queue, &data, sizeof(data))) ;
        ck_assert_uint_eq(data, 1);
        data = 13;
        ck_assert(Dequeue(queue, &data, sizeof(data)));
        ck_assert_uint_eq(data, 1);
        data = 13;
        ck_assert(Front(queue, &data, sizeof(data))) ;
        ck_assert_uint_eq(data, 2);
        data = 13;
        ck_assert(Dequeue(queue, &data, sizeof(data)));
        ck_assert_uint_eq(data, 2);
        ck_assert(Front(queue, &data, sizeof(data))) ;
        ck_assert_uint_eq(data, 3);
        data = 13;
        ck_assert(Dequeue(queue, &data, sizeof(data)));
        ck_assert_uint_eq(data, 3);
        ck_assert(QueueEmpty(queue));
    }
END_TEST

Suite * queue_suite(void)
{
    Suite *s;
    TCase *tc_elements_number;

    s = suite_create("Queue");

    /* Core test case */
    tc_elements_number = tcase_create("Elements");
    tcase_add_checked_fixture(tc_elements_number, setup_queue, teardown_queue);
    tcase_add_test(tc_elements_number, test_Queue_Empty);
    tcase_add_test(tc_elements_number, test_Queue_one_element);
    tcase_add_test(tc_elements_number, test_Queue_two_elements);
    tcase_add_test(tc_elements_number, test_Queue_three_elements);
    suite_add_tcase(s, tc_elements_number);

    return s;
}


