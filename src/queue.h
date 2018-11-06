//
// Created by alanpark on 18. 11. 6.
//

#pragma once

#include <stdint.h>
#include "linkedlist.h"
#include "linkedlist.h"

typedef LinkedList Queue;

#define CreateQueue(a) CreateLinkedList((a));
#define Enqueue(a,b) PushBack((a), (b));
bool Dequeue(Queue*, void*, size_t);
#define DestroyQueue(a) DestroyLinkedList((a));
#define QueueEmpty(a) ListEmpty((a))
