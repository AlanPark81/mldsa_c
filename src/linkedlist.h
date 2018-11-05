#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct LinkedList LinkedList;
typedef struct ListIterator ListIterator;

LinkedList *CreateLinkedList(size_t elem_size);
void PushBack(LinkedList *list, void *buffer);
void PushFront(LinkedList *list, void *buffer);
bool Front(LinkedList *list, void *buffer, size_t length);
bool Back(LinkedList *list, void *buffer, size_t length);
void DestroyLinkedList(LinkedList *list);

ListIterator* GetIterator(const LinkedList* list);
bool GetCurrValue(ListIterator* iterator, void *buffer, size_t length);
bool Next(ListIterator* iterator);
bool Prev(ListIterator* iterator);