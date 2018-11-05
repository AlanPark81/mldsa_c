#include <stdlib.h>
#include <memory.h>
#include "linkedlist.h"
typedef struct ListNode ListNode;

struct ListNode {
    ListNode *prev;
    ListNode *next;
    unsigned char data[1];
};

ListNode *CreateNode(void *data_ptr, const size_t length ) {
    ListNode *created = malloc(sizeof(ListNode)+length-1);
    created->next = NULL;
    created->prev = NULL;
    memcpy(created->data, data_ptr, length);
    return created;
}

struct LinkedList {
    ListNode *head;
    ListNode *tail;
    size_t data_len;
};

struct ListIterator{
    ListNode* curr_node;
};

LinkedList *CreateLinkedList(size_t elem_size){
    return NULL;
}
void PushBack(LinkedList *list, void *buffer) {
}

void PushFront(LinkedList *list, void *buffer) {
}

bool Front(LinkedList *list, void *buffer, size_t length) {
    return true;
}
bool Back(LinkedList *list, void *buffer, size_t length) {
    return true;
}

void DestroyLinkedList(LinkedList *list){}

ListIterator* GetIterator(const LinkedList* list) {
}

bool GetCurrValue(ListIterator* iterator, void *buffer, size_t length) {
    return true;
}

bool Next(ListIterator* iterator) {
    return true;
}

bool Prev(ListIterator* iterator) {
    return true;
}