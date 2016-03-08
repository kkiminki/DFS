//Kyler Kiminki
//kkiminki
//cmps101
//List.c
//List ADT

#include<stdio.h>
#include<stdlib.h>
#include"List.h"

//structs

//private node
typedef struct nodeObj{
   int item;
   struct nodeObj* next;
   struct nodeObj* prev;
} nodeObj;

typedef nodeObj* node;

typedef struct ListObj{
   node front;
   node back;
   node current;
   node cursor;
} ListObj;

//Constructors and Destructors

//Creates and returns a new node object
node newNode(int item){
   node n = malloc(sizeof(nodeObj));
   n->item = item;
   n->next = NULL;
   n->prev = NULL;
   return(n);
}

//Frees the node from memory
void freeNode(node* pN){
   if(pN!=NULL && *pN!=NULL){
      free(*pN);
      *pN = NULL;

   }
}

//Returns a reference to a new empty list
List newList(void){
   List L;
   L = malloc(sizeof(ListObj));
   L->front = NULL;
   L->back = NULL;
   L->current = NULL;
   L->cursor = NULL;
   return(L);
}

//Frees all heap memory associated with the List *pL, and sets *pL to NULL
void freeList(List* pL){
   if(pL!=NULL && *pL!=NULL){
      while(!isEmpty(*pL)){
         deleteBack(*pL);
      }
      free(*pL);
      *pL = NULL;
   }
}

//Access functions

//Returns the value at the front of the list
int front(List L){
   if(L==NULL){
      printf("List: front(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: front(): List is empty\n");
      exit(1);
   }
   return(L->front->item);
}

//Returns the value at the back of the list
int back(List L){
   if(L==NULL){
      printf("List: back(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: back(): List is empty\n");
      exit(1);
   }
   return(L->back->item);
}

//Returns the value of the cursor
int get(List L){
   if(L==NULL){
     printf("List: get(): List is NULL\n");
     exit(1);
   }if(isEmpty(L)){
      printf("List: get(): List is empty\n");
      exit(1);
   }if(index(L)==-1){
      printf("List: get(): Cursor is undefined\n");
      exit(1);
   }
   return(L->cursor->item);
}

//Returns the number of elements in the list
int length(List L){
   if(L==NULL){
      return(0);
   }if(isEmpty(L)){
      return(0);
   }
   L->current = L->front;
   int count = 0;
   while(L->current!=NULL){
      L->current = L->current->next;
      count++;
   }
   return(count);
}

//Returns the index of the cursor
int index(List L){
   if(L==NULL){
      printf("List: index(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      return(-1);
   }if(L->cursor==NULL){
      return(-1);
   }
   L->current = L->front;
   int count = 0;
   while(L->current!=NULL && L->current!=L->cursor){
      L->current = L->current->next;
      count++;
   }
   return(count);
}

//Returns 1 is the two lists are equal and 0 if they are not
int equals(List A, List B){
   if(A==NULL || B==NULL){
      return 0;
   }if(isEmpty(A) && isEmpty(B)){
      return 1;
   }if(isEmpty(A) || isEmpty(B)){
      return 0;
   }
   if(length(A)!=length(B)){
      return 0;
   }
   A->current = A->front;
   B->current = B->front;
   while(A->current!=NULL){
      if(B->current->item != A->current->item){
         return 0;
      }
      A->current = A->current->next;
      B->current = B->current->next;
   }
   return 1;
}

//Manipulation procedures

//clears list
void clear(List L){
   moveFront(L);
   while(length(L) != 0){
      deleteBack(L);
   }
}


//moves the cursor to the front of the list
void moveFront(List L){
   if(L==NULL){
      printf("List: moveFront(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: moveFront(): List is empty\n");
      exit(1);
   }
   L->cursor = L->front;
}

//moves the cursor to the back of the list
void moveBack(List L){
   if(L==NULL){
      printf("List: moveBack(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: moveBack(): List is empty\n");
      exit(1);
   }
   L->cursor = L->back;
}

//moves the cursor to the previous node
void movePrev(List L){
   if(L==NULL){
      printf("List: movePrev(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: movePrev(): List is empty\n");
      exit(1);
   }if(index(L)==-1){
      printf("List: movePrev(): Cursor is undefined\n");
      exit(1);
   }if(L->cursor == L->front){
      L->cursor = NULL;
   }else{
      L->cursor = L->cursor->prev;
   }
}

//moves the cursor to the next node
void moveNext(List L){
   if(L==NULL){
      printf("List: moveNext(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: moveNext(): List is empty\n");
      exit(1);
   }if(index(L)==-1){
      printf("List: moveNext(): Cursor is not defined\n");
      exit(1);
   }if(L->cursor==L->back){
      L->cursor = NULL;
   }else{
      L->cursor = L->cursor->next;
   }
}

//prepends item onto the front of the list
void prepend(List L, int item){
   if(L==NULL){
      printf("List: prepend(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      node n = newNode(item);
      L->front = n;
      L->back = n;
   }else{
      node n = newNode(item);
      n->next = L->front;
      L->front->prev = n;
      L->front = n;
   }
}

//appends item onto the back of the list
void append(List L, int item){
   if(L==NULL){
      printf("List: append(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      node n = newNode(item);
      L->back = n;
      L->front = n;
   }else{
      node n = newNode(item);
      n->prev = L->back;
      L->back->next = n;
      L->back = n;
   }
}

//inserts item before the cursor
void insertBefore(List L, int item){
   if(L==NULL){
      printf("List: insertBefore(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: insertBefore(): List is empty\n");
      exit(1);
   }if(index(L)==-1){
      printf("List: insertBefore(): Cursor is undefined\n");
      exit(1);
   }if(L->cursor==L->front){
      prepend(L, item);
   }else{
      //node b = L->cursor->prev;
      node n = newNode(item);
      n->next = L->cursor;
      n->prev = L->cursor->prev;
      L->cursor->prev->next = n;
      L->cursor->prev = n;
   }
}

//inserts item after the cursor
void insertAfter(List L, int item){
   if(L==NULL){
      printf("List: insertAfter(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: insertAfter(): List is empty\n");
      exit(1);
   }if(index(L)==-1){
      printf("List: insertAfter(): Cursor is undefined\n");
      exit(1);
   }if(L->cursor==L->back){
      append(L, item);
   }else{
      //node b = L->cursor->next;
      node n = newNode(item);
      n->next = L->cursor->next;
      n->prev = L->cursor;
      L->cursor->next->prev = n;
      L->cursor->next = n;
   }
}

//deletes the item at the front of the list
void deleteFront(List L){
   if(L==NULL){
      printf("List: deleteFront(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: deleteFront(): List is empty\n");
      exit(1);
   }
   L->current = L->front->next;
   if(L->cursor==L->front){
      freeNode(&L->cursor);
   }
   freeNode(&L->front);
   L->front = L->current;
}

//deletes the item at the back of the list
void deleteBack(List L){
   if(L==NULL){
      printf("List: deleteBack(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: deleteBack(): List is empty\n");
      exit(1);
   }
   L->current = L->back->prev;
   if(L->cursor==L->back){
      L->cursor = NULL;
   }
   if(L->back == L->front){
      L->front = NULL;
   }
   freeNode(&L->back);
   L->back = L->current;
   //L->back->next = NULL;
}

//deletes the cursor
void delete(List L){
   if(L==NULL){
      printf("List: delete(): List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      printf("List: delete(): List is empty\n");
      exit(1);
   }if(index(L)==-1){
      printf("List: delete(): Cursor is undefined\n");
      exit(1);
   }if(L->cursor==L->front){
      deleteFront(L);
      return;
   }if(L->cursor==L->back){
      deleteBack(L);
      return;
   }
   L->cursor->prev->next = L->cursor->next;
   L->cursor->next->prev = L->cursor->prev;
   freeNode(&L->cursor);
   L->cursor = NULL;
}

//Returns 1 if the list is empty and 0 if it is not
int isEmpty(List L){
   if(L->front==NULL){
      return 1;
   }
   return 0;
}

//Prints out the list to the file pointer
void printList(FILE* out, List L){
   if(out==NULL){
      printf("List: printList(): File could not be read\n");
      exit(1);
   }if(L==NULL){
      printf("List: printList(): List is NULL\n");
      exit(1);
   }
   L->current = L->front;
   while(L->current != NULL){
      fprintf(out, "%d ",L->current->item);
      L->current = L->current->next;
   }
}

//Returns a copy of the list
List copyList(List L){
   List A = newList();
   if(L==NULL){
      printf("List: copy: List is NULL\n");
      exit(1);
   }if(isEmpty(L)){
      return A;
   }
   L->current = L->front;
   while(L->current != NULL){
      append(A, L->current->item);
      L->current = L->current->next;
   }
   return A;
}
