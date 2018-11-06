//
// Created by alanpark on 18. 11. 6.
//

#include "queue.h"

bool Dequeue(Queue* queue, void* data, const size_t length) {
    if(ListEmpty(queue)) {
        return false;
    }
    PopFront(queue, data, length);
    return true;
}