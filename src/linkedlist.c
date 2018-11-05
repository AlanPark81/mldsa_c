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

void Front(LinkedList *list, void *buffer, size_t length) {
}
void Back(LinkedList *list, void *buffer, size_t length) {
}

void DestroyLinkedList(LinkedList *list){}

ListIterator* GetIterator(const LinkedList* list) {
}

bool GetCurrValue(ListIterator* iterator, void *buffer, size_t length);
bool Next(ListIterator* iterator);
bool Prev(ListIterator* iterator);