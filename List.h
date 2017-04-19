//===============================================================================================================
// List.h
// Header file for Doubly Linked List ADT
//
// Yona Edell
// CruzID: yedell
// CMPS 101
// PA4
// 02/18/2017
//===============================================================================================================

#include <stdio.h>

#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_

// Exported type ------------------------------------------------------------------------------------------------

typedef struct ListObj* List;

// Constructors-Destructors -------------------------------------------------------------------------------------

List newList(void);
void freeList(List* pL);

// Access Functions ---------------------------------------------------------------------------------------------

int length(List L);
int index(List L);
int front(List L);
int back(List L);
int get(List L);
int equals(List A, List B);

// Manipulation Procedures --------------------------------------------------------------------------------------

void clear(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, int data);
void append(List L, int data);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);

// Other Operations ---------------------------------------------------------------------------------------------

void printList(FILE* out, List L);
List copyList(List L);
List concatList(List A, List B);

#endif // LIST_H