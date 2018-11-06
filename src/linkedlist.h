#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct _LinkedList LinkedList;
typedef struct _ListNode ListNode;
typedef struct _ListIterator{
    ListNode* curr_node;
    size_t data_len;
} ListIterator;

LinkedList *CreateLinkedList(size_t elem_size);
void PushBack(LinkedList *list, void *buffer);
void PushFront(LinkedList *list, void *buffer);
void PopBack(LinkedList *list, void *buffer, size_t length);
void PopFront(LinkedList *list, void *buffer, size_t length);
bool Front(LinkedList *list, void *buffer, size_t length);
bool Back(LinkedList *list, void *buffer, size_t length);
bool InsertAfter(LinkedList *list, ListIterator* iterator, void *buffer);
bool InsertBefore(LinkedList *list, ListIterator* iterator, void *buffer);
bool RemoveAt(LinkedList *linked_list, ListIterator *iterator);
bool ListEmpty(LinkedList *list);
void DestroyLinkedList(LinkedList *list);

ListIterator GetIterator(const LinkedList* list);
bool GetCurrValue(ListIterator* iterator, void *buffer, size_t length);
bool Next(ListIterator* iterator);
bool Prev(ListIterator* iterator);