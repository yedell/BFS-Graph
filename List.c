//===============================================================================================================
// List.c
// Implementation file for Doubly Linked List ADT
//
// Yona Edell
// CruzID: yedell
// CMPS 101
// PA4
// 02/18/2017
//===============================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// Structs ------------------------------------------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
    int data;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private ListObj type
typedef struct ListObj{
    Node front;
    Node back;
    Node cursor;
    int index;
    int length;
} ListObj;

// Constructors-Destructors -------------------------------------------------------------------------------------

// Private.
Node newNode(int data){ // Returns reference to new Node object. Initializes next and data fields.
    Node N = malloc(sizeof(NodeObj));
    N->data = data;
    N->next = NULL;
    N->prev = NULL;
    return(N);
}

List newList(void) { // Returns reference to new empty List object.
    List L;
    L = malloc(sizeof(ListObj));
    L->front = L->back = L->cursor = NULL;
    L->length = 0;
    L->index = -1;
    return (L);
}

// Private.
void freeNode(Node* pN){ // Frees heap memory pointed to by *pN, sets *pN to NULL.
    if( pN!=NULL && *pN!=NULL ){
        free(*pN);
        *pN = NULL;
    }
}

void freeList(List* pL) { // Frees all heap memory associated with List *pL, and sets *pL to NULL.
    if(pL != NULL && *pL != NULL) {
        Node temp = (*pL)->front;
        while(temp != NULL) {
            Node N = temp;
            temp = temp->next;
            free(N);
        }
        free(*pL);
        *pL = NULL;
    }
}

// Access functions ---------------------------------------------------------------------------------------------

int length(List L) {
    // Returns the number of elements in this List.
    if(L == NULL) {
        printf("List Error: calling \"length()\" on NULL List reference\n");
        exit(1);
    }
    return(L->length);
}

int index(List L) {
    // If cursor is defined, returns the index of the cursor element,
    // otherwise returns -1.
    if(L == NULL) {
        printf("List Error: calling \"index()\" on NULL List reference\n");
        exit(1);
    }
    if(L->cursor != NULL) {
        return L->index;
    }
    return -1;
}

int front(List L) {
    // Returns front element.
    if(L == NULL) {
        printf("List Error: calling \"front()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"front()\" on empty List reference\n");
        exit(1);
    }
    return(L->front->data);
}

int back(List L) {
    // Returns back element. Pre: length()>0
    if(L == NULL) {
        printf("List Error: calling \"back()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"back()\" on empty List reference\n");
        exit(1);
    }
    return(L->back->data);
}

int get(List L) {
    // Returns cursor element.
    if(L == NULL) {
        printf("List Error: calling \"get()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"get()\" on empty List reference\n");
        exit(1);
    }
    if(L->index < 0) {
        printf("List Error: calling \"get()\" on List reference with undefined index\n");
        exit(1);
    }
    return L->cursor->data;
}

int equals(List A, List B) {
    // Returns true if this List and L are the same integer
    // sequence. The cursor is ignored in both lists.
    if(A == NULL || B == NULL) {
        printf("List Error: calling \"equals()\" on NULL List reference\n");
        exit(1);
    }
    if(A->length != B->length) { // If lengths are different, returns false
        return 0;
    }
    int eq = 1;
    Node aNode = A->front;
    Node bNode = B->front;
    for(int i = 0; i < A->length; i++) { // Loop through Lists comparing values
        if(aNode->data != bNode->data) {
            eq = 0; // If data doesn't match, returns false
            break;
        }
        aNode = aNode->next;
        bNode = bNode->next;
    }
    return eq;
}

// Manipulation procedures --------------------------------------------------------------------------------------

void clear(List L) {
    // Resets this List to its original empty state.
    if(L != NULL) {
        Node temp = L->front;
        while(temp != NULL) {
            Node N = temp;
            temp = temp->next;
            free(N);
        }
        L->front = L->back = L->cursor = NULL;
        L->length = 0;
        L->index = -1;
    }
}

void moveFront(List L) {
    // If List is non-empty, places the cursor under the front element,
    // otherwise does nothing.
//    if(L == NULL) {
//        printf("List Error: calling \"moveFront()\" on NULL List reference\n");
//        exit(1);
//    }
    if(L->length > 0) {
        L->cursor = L->front;
        L->index = 0;
    }
}

void moveBack(List L) {
    // If List is non-empty, places the cursor under the back element,
    // otherwise does nothing.
//    if(L == NULL) {
//        printf("List Error: calling \"moveBack()\" on NULL List reference\n");
//        exit(1);
//    }
    if(L->length > 0) {
        L->cursor = L->back;
        L->index = L->length -1;
    }

}

void movePrev(List L) {
    // If cursor is defined and not at front, moves cursor one step toward
    // front of this List, if cursor is defined and at front, cursor becomes
    // undefined, if cursor is undefined does nothing.
    if(L == NULL) {
        printf("List Error: calling \"movePrev()\" on NULL List reference\n");
        exit(1);
    }
    if(L->index < L->length && L->index >= 0) {
        if(L->index != 0) { // If cursor not at front, moves cursor to previous node
            L->index--;
            L->cursor = L->cursor->prev;
        }
        else { // If cursor is at front, becomes undefined
            L->index = -1;
            L->cursor = NULL;
        }
    }
}

void moveNext(List L) {
    // If cursor is defined and not at back, moves cursor one step toward
    // back of this List, if cursor is defined and at back, cursor becomes
    // undefined, if cursor is undefined does nothing.
    if(L == NULL) {
        printf("List Error: calling \"moveNext()\" on NULL List reference\n");
        exit(1);
    }
    if(L->index < L->length && L->index >= 0) {
        if(L->index != L->length -1) { // If cursor not at back, moves cursor to next node
            L->cursor = L->cursor->next;
            L->index++;
        }
        else { // If cursor is at back, becomes undefined
            L->index = -1;
            L->cursor = NULL;
        }
    }
}

void prepend(List L, int data) {
    // Insert new element into this List. If List is non-empty,
    // insertion takes place before front element.
    if(L == NULL) {
        printf("List Error: calling prepend() on NULL List reference\n");
        exit(1);
    }
    Node temp = newNode(data);
    if(L->length < 1) { // If empty List
        L->front = L->back = temp;
    }
    else { // If non empty List
        L->front->prev = temp;
        temp->next = L->front;
        L->front = L->front->prev;
    }
    if(L->index >= 0) { // If cursor defined, adjust the index
        L->index++;
    }
    L->length++;
}

void append(List L, int data) {
    // Insert new element into this List. If List is non-empty,
    // insertion takes place after back element.
    if(L == NULL) {
        printf("List Error: calling \"append()\" on NULL List reference\n");
        exit(1);
    }
    Node temp = newNode(data);
    if(L->length < 1) { // If empty List
        L->front = L->back = temp;
    }
    else { // If non empty List
        L->back->next = temp;
        temp->prev = L->back;
        L->back = L->back->next;
    }
    L->length++;
}

void insertBefore(List L, int data) {
    // Insert new element before cursor.
    if(L == NULL) {
        printf("List Error: calling \"insertBefore()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"insertBefore()\" on empty List reference\n");
        exit(1);
    }
    if(L->index < 0) {
        printf("List Error: calling \"insertBefore()\" on List reference with undefined index\n");
        exit(1);
    }
    if(L->index == 0) { // If index is at front, prepend
        prepend(L, data);
    }
    else {
        Node temp = newNode(data);
        L->cursor->prev->next = temp;
        temp->next = L->cursor;
        temp->prev = L->cursor->prev;
        L->cursor->prev = temp;
        L->length++;
        L->index++;
    }
}

void insertAfter(List L, int data) {
    // Inserts new element after cursor.
    if(L == NULL) {
        printf("List Error: calling \"insertAfter()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"insertAfter()\" on empty List reference\n");
        exit(1);
    }
    if(L->index < 0) {
        printf("List Error: calling \"insertAfter()\" on List reference with undefined index\n");
        exit(1);
    }
    if(L->index == L->length -1) { // If index is at end, append
        append(L, data);
    }
    else {
        Node temp = newNode(data);
        temp->next = L->cursor->next;
        temp->prev = L->cursor;
        L->cursor->next = temp;
        temp->next->prev = temp;
        L->length++;
    }
}

void deleteFront(List L) {
    // Deletes the front element.
    if(L == NULL) {
        printf("List Error: calling \"deleteFront()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"deleteFront()\" on empty List reference\n");
        exit(1);
    }
    if(L->length == 1) { // If length 1, head and tail are same
        clear(L);
    }
    else {
        Node temp = L->front;
        L->front = L->front->next;
        L->front->prev = NULL;
        freeNode(&temp);
        L->length--;

        if(L->index == 0) { // If cursor is at front, becomes undefined
            L->cursor = NULL;
            L->index = -1;
        }
        else if(L->index != -1) { // If cursor is defined, index is decremented
            L->index--;
        }
    }
}

void deleteBack(List L) {
    // Deletes the back element.
    if(L == NULL) {
        printf("List Error: calling \"deleteBack()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"deleteBack()\" on empty List reference\n");
        exit(1);
    }
    if(L->length == 1) { // If length 1, head and tail are same
        clear(L);
    }
    else {
        Node temp = L->back;
        L->back = L->back->prev;
        L->back->next = NULL;
        freeNode(&temp);

        if(L->index == L->length -1) { // If cursor is at back, becomes undefined
            L->cursor = NULL;
            L->index = -1;
        }
        L->length--;
    }
}

void delete(List L) {
    // Deletes cursor element, making cursor undefined
    if(L == NULL) {
        printf("List Error: calling \"delete()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"delete()\" on empty List reference\n");
        exit(1);
    }
    if(L->index < 0) {
        printf("List Error: calling \"delete()\" on List reference with undefined index\n");
        exit(1);
    }
    if(L->index == 0) { // When index is at front
        deleteFront(L);
    }
    else if(L->index == L->length -1) { // When index is at back
        deleteBack(L);
    }
    else {
        L->cursor->prev->next = L->cursor->next;
        L->cursor->next->prev = L->cursor->prev;
        freeNode(&L->cursor);
        L->index = -1;
        L->length--;
    }
}

// Other operations ---------------------------------------------------------------------------------------------

void printList(FILE* out, List L) {
    if(length(L) != 0) { // Prints list if non-empty

        Node N = L->front;
        for( ; N != L->back; N = N->next){
            fprintf(out, "%d ", N->data);
        }
        if(N == L->back) {
            fprintf(out, "%d", N->data);
        }
    }
}

List copyList(List L) {
    // Returns a new List representing the same integer sequence as this
    // List. The cursor in the new list is undefined, regardless of the
    // state of the cursor in this List. This List is unchanged.
    if(L == NULL) {
        printf("List Error: calling \"copyList()\" on NULL List reference\n");
        exit(1);
    }
    if(L->length < 1) {
        printf("List Error: calling \"copyList()\" on empty List reference\n");
        exit(1);
    }
    List copy = newList();
    Node N = L->front;
    while(N != NULL) {
        append(copy, N->data);
        N = N->next;
    }
    return copy;
}

List concatList(List A, List B) {
    // Returns a new List which is the concatenation of
    // A list followed by B. The cursor in the new List
    // is undefined, regardless of the states of the cursors
    // in A and B. The states of A and B are
    // unchanged.
    if(A == NULL || B == NULL) {
        printf("List Error: calling \"concatList()\" on NULL List reference\n");
        exit(1);
    }
    if(A->length < 1 || B->length < 1) {
        printf("List Error: calling \"concatList()\" on empty List reference\n");
        exit(1);
    }
    List concat = copyList(A);
    Node bNode = B->front;
    while(bNode != NULL) {
        append(concat, bNode->data);
        bNode = bNode->next;
    }
    return concat;
}