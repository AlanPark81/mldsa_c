//
// Created by alanp on 2019-02-16.
//

#ifndef MLDSA_C_QSORT_H
#define MLDSA_C_QSORT_H
#include <stddef.h>

void QSort(void* array, size_t elem_count, size_t elem_size, int (*comp)(const void*, const void*));

#endif //MLDSA_C_QSORT_H
