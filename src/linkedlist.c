#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "linkedlist.h"

struct _ListNode {
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

struct _LinkedList {
    ListNode *head;
    ListNode *tail;
    size_t data_len;
};

LinkedList *CreateLinkedList(size_t elem_size){
    LinkedList *created = malloc(sizeof(LinkedList));
    created->data_len = elem_size;
    created->head = NULL;
    created->tail = NULL;
    return created;
}
void PushBack(LinkedList *list, void *buffer) {
    if( list == NULL ) {
        exit(1);
    } else if ( list->head == NULL ) {
        list->head = CreateNode(buffer, list->data_len);
        list->tail = list->head;
    } else {
        ListNode* node = CreateNode(buffer, list->data_len);
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = list->tail->next;
    }
}

void PushFront(LinkedList *list, void *buffer) {
    if( list == NULL ) {
        exit(1);
    } else if ( list->head == NULL ) {
        list->head = CreateNode(buffer, list->data_len);
        list->tail = list->head;
    } else {
        ListNode* node = CreateNode(buffer, list->data_len);
        node->next = list->head;
        list->head->prev = node;
        list->head = list->head->prev;
    }
}

void PopBack(LinkedList *list, void *buffer, const size_t length) {
    if(list == NULL || list->head == NULL || length < list->data_len ) {
        return;
    }

    ListNode* node = list->tail;
    if( list->head == list->tail ){
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
    }
    memcpy(buffer, node->data, list->data_len);
    free(node);
}
void PopFront(LinkedList *list, void *buffer, const size_t length) {
    if(list == NULL || list->head == NULL || length < list->data_len ) {
        return;
    }

    ListNode* node = list->head;
    if( list->head == list->tail ){
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
    }
    memcpy(buffer, node->data, list->data_len);
    free(node);
}

bool Front(LinkedList *list, void *buffer, size_t length) {
    if(list == NULL || list->head == NULL || length < list->data_len) {
        return false;
    }
    memcpy(buffer, list->head->data, list->data_len);
    return true;
}
bool Back(LinkedList *list, void *buffer, size_t length) {
    if(list == NULL || list->head == NULL || length < list->data_len) {
        return false;
    }
    memcpy(buffer, list->tail->data, list->data_len);
    return true;
}


bool InsertAfter(LinkedList *list, ListIterator* iterator, void *buffer) {
    if( list == NULL || iterator == NULL || iterator->curr_node == NULL){
        return false;
    }
    ListNode *next_node = iterator->curr_node->next;
    ListNode *new_node = CreateNode(buffer, iterator->data_len);
    new_node->prev = iterator->curr_node;
    new_node->next = next_node;
    iterator->curr_node->next = new_node;
    if( next_node != NULL ) {
        next_node->prev = new_node;
    }
    return true;
}
bool InsertBefore(LinkedList *list, ListIterator* iterator, void *buffer) {
    if( list == NULL || iterator == NULL || iterator->curr_node == NULL){
        return false;
    }
    ListNode *prev_node = iterator->curr_node->prev;
    ListNode *new_node = CreateNode(buffer, iterator->data_len);
    new_node->next = iterator->curr_node;
    new_node->prev = prev_node;
    iterator->curr_node->prev = new_node;
    if( prev_node != NULL ) {
        prev_node->next = new_node;
    }
    return true;
}

bool RemoveAt(LinkedList *linked_list, ListIterator *iterator) {
    if(linked_list == NULL || iterator == NULL || iterator->curr_node == NULL){
        return false;
    }
    ListNode* prev_node = iterator->curr_node->prev;
    ListNode* next_node = iterator->curr_node->next;
    if( prev_node != NULL ) {
        prev_node->next = next_node;
    } else {
        linked_list->head = next_node;
    }

    if( next_node != NULL ) {
        next_node->prev = prev_node;
    } else {
        linked_list->tail = prev_node;
    }
    free(iterator->curr_node);
    iterator->curr_node = next_node;
    return true;
}

bool ListEmpty(LinkedList *list) {
    return (list == NULL || list->head == NULL );
}

void DestroyLinkedList(LinkedList *list) {
    ListNode* node = list->head;
    while( node != NULL ) {
        free(node);
        node = node->next;
    }
    free(list);
}

ListIterator GetIterator(const LinkedList* list) {
    ListIterator iterator;
    iterator.curr_node = list->head;
    iterator.data_len = list->data_len;
    return iterator;
}

bool GetCurrValue(ListIterator* iterator, void *buffer, size_t length) {
    if(iterator -> curr_node == NULL || length < iterator->data_len ) {
        return false;
    }
    memcpy(buffer, iterator->curr_node->data, iterator->data_len);
    return true;
}

bool Next(ListIterator* iterator) {
    if(iterator->curr_node == NULL ) {
        return false;
    }
    iterator->curr_node = iterator->curr_node->next ;
    return true;
}

bool Prev(ListIterator* iterator) {
    if(iterator->curr_node == NULL ) {
        return false;
    }
    iterator->curr_node = iterator->curr_node->prev ;
    return true;
}