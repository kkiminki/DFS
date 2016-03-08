//Kyler Kiminki
//kkiminki
//cmps101
//List.h

#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_

//Exported type
typedef struct ListObj* List;

//Constructors ~ Destructors

//Returns reference to new empty list
List newList(void);

//Frees all heap memory associated with List *pL and sets *pL to NULL
void freeList(List* pL);

//Access functions

//Returns the length of List L
int length(List L);

//Returns the index of the cursor node. If cursor is
//undefined then it returns -1
int index(List L);

//Returns the value of the front of the list
int front(List L);

//Returns value of the cursor
int get(List L);

//Returns the value of the back of the list
int back(List L);

//Returns 1 if the lists are equal and 0 if the lists are not
int equals(List A, List B);

//Manipulation procedures

//clears the list
void clear(List L);

//Moves the cursor to the front of the list
void moveFront(List L);

//Moves the cursor to the back of the list
void moveBack(List L);

//Moves the cursor to the previous node
void movePrev(List L);

//Moves the cursor to the next node
void moveNext();

//Inserts item to the front of the list
void prepend(List L, int item);

//Inserts item to the back of the list
void append(List L, int item);

//Inserts item before the cursor
void insertBefore(List L, int item);

//Insert item after the cursor
void insertAfter(List L, int item);

//Deletes the item at the front of the list
void deleteFront(List L);

//Deletes the item at the back of the list
void deleteBack(List L);

//Deletes the cursor
void delete(List L);


//Other operations

//Prints the list out to FILE* out
void printList(FILE* out, List L);

//Creates and returns a copy of List L
List copyList(List L);

//Returns 1 if the list is empty and 0 if the list is not
int isEmpty(List L);

#endif
