#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "boolean.h"

typedef int ElType;
typedef struct node* Address;
typedef struct node {
    ElType info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType val);

typedef Address List;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/****************** PEMBUATAN LIST KOSONG ******************/
void create_linked_list(List *l);

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_linked_list(List l);

/****************** GETTER SETTER ******************/
ElType getElmt_linked_list(List l, int idx);

void setElmt_linked_list(List *l, int idx, ElType val);

int indexOf_linked_list(List l, ElType val);

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst_linked_list(List *l, ElType val);

void insertLast_linked_list(List *l, ElType val);

void insertAt_linked_list(List *l, ElType val, int idx);

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst_linked_list(List *l, ElType *val);

void deleteLast_linked_list(List *l, ElType *val);

void deleteAt_linked_list(List *l, int idx, ElType *val);


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList_linked_list(List l);

int length_linked_list(List l);

#endif