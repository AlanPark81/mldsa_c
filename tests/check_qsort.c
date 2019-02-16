#include <config.h>
#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "qsort.h"

void setup_qsort(void) {}

void teardown_qsort(void) {}

int IntCompare(const void* a, const void* b) {
    register int l = *(const int* const)a;
    register int r = *(const int* const)b;
    return l - r;
}

START_TEST(test_Qsort_empty)
{
    int array[1] = {3};
    QSort(array, 0, sizeof(int), IntCompare);
    ck_assert(array[0] == 3);
}
END_TEST

START_TEST(test_Qsort_one)
{
    int array[1] = {3};
    QSort(array, 1, sizeof(int), IntCompare);
    ck_assert(array[0] == 3);
}
END_TEST

START_TEST(test_Qsort_two)
{
    int array[2] = {3,5};
    QSort(array, 2, sizeof(int), IntCompare);
    ck_assert(array[0] == 3);
    ck_assert(array[1] == 5);
}
END_TEST

START_TEST(test_Qsort_three)
{
    int array[3] = {3,1,5};
    QSort(array, 3, sizeof(int), IntCompare);
    ck_assert(array[0] == 1);
    ck_assert(array[1] == 3);
    ck_assert(array[2] == 5);
}
END_TEST

START_TEST(test_Qsort_four)
    {
        int array[4] = {3, 1, 5, 2};
        QSort(array, 4, sizeof(int), IntCompare);
        ck_assert(array[0] == 1);
        ck_assert(array[1] == 2);
        ck_assert(array[2] == 3);
        ck_assert(array[3] == 5);
    }
END_TEST

START_TEST(test_Qsort_five)
    {
        int array[5] = {3, 1, 5, 2, 4};
        QSort(array, 5, sizeof(int), IntCompare);
        ck_assert(array[0] == 1);
        ck_assert(array[1] == 2);
        ck_assert(array[2] == 3);
        ck_assert(array[3] == 4);
        ck_assert(array[4] == 5);
    }
END_TEST

Suite * qsort_suite(void)
{
    Suite *s;
    TCase *tc_elements_number;

    s = suite_create("QSort");

    /* Core test case */
    tc_elements_number = tcase_create("Elements");
    tcase_add_checked_fixture(tc_elements_number, setup_qsort, teardown_qsort);
    tcase_add_test(tc_elements_number, test_Qsort_empty);
    tcase_add_test(tc_elements_number, test_Qsort_one);
    tcase_add_test(tc_elements_number, test_Qsort_two);
    tcase_add_test(tc_elements_number, test_Qsort_three);
    tcase_add_test(tc_elements_number, test_Qsort_four);
    tcase_add_test(tc_elements_number, test_Qsort_five);
    suite_add_tcase(s, tc_elements_number);
    return s;
}


