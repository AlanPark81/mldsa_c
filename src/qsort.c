//
// Created by alanp on 2019-02-16.
//

#include "qsort.h"

int Partition(void* array, size_t elem_count, size_t elem_size, int (*comp)(const void*, const void*)){
    void* pivot = array + (elem_size * (elem_count - 1));
    void* write_pos = array;
    char swap_buffer[elem_size];
    for(int i = 0; i < elem_count; i++) {
        void* curr_elem = array + i * elem_size;
        if((*comp)(curr_elem, pivot) < 0) {
            if(write_pos != curr_elem) {
                memcpy(swap_buffer, write_pos, elem_size);
                memcpy(write_pos, curr_elem, elem_size);
                memcpy(curr_elem, swap_buffer, elem_size);
            }
            write_pos += elem_size;
        }
    }
    memcpy(swap_buffer, write_pos, elem_size);
    memcpy(write_pos, pivot, elem_size);
    memcpy(pivot, swap_buffer, elem_size);
    return (write_pos - array) / elem_size;
}

void QSort(void* array, size_t elem_count, size_t elem_size, int (*comp)(const void*, const void*)) {
    if (elem_count < 2) return;
    int end_of_left = Partition(array, elem_count, elem_size, comp);
    QSort(array, end_of_left, elem_size, comp);
    QSort(array + (end_of_left + 1) * elem_size, elem_count - end_of_left - 1, elem_size, comp);
}
