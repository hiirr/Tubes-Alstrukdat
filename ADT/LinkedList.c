#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Address newNode(ElType val){
    Address p = (Address)malloc(sizeof(Node));
    if (p!=NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
};

/****************** PEMBUATAN LIST KOSONG ******************/
void create_linked_list(List *l){
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_linked_list(List l){
    return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt_linked_list(List l, int idx){
    Address p = FIRST(l);
    int i = 0;
    while (i < idx && p != NULL){
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt_linked_list(List *l, int idx, ElType val){
    Address p = FIRST(*l);
    int i = 0;
    while(p != NULL && i < idx){
        p = NEXT(p);
        i += 1;
    }
    INFO(p) = val;
}

int indexOf_linked_list(List l, ElType val){
    Address p = FIRST(l);
    int cnt = 0;
    boolean isFound = false;
    while(p != NULL && !isFound){
        if(INFO(p) == val){
            isFound = true;
        }
        else{
            cnt += 1;
            p = NEXT(p);
        }
    }
    if(isFound){
        return cnt;
    }
    else{
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst_linked_list(List *l, ElType val){
    Address p;
    p = newNode(val);
    if(p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast_linked_list(List *l, ElType val){
    if(isEmpty_linked_list(*l)){
        insertFirst_linked_list(l, val);
    }
    else{
        Address p, loc;
        p = newNode(val);
        if(p != NULL){
            loc = *l;
            while(NEXT(loc) != NULL){
                loc = NEXT(loc);
            }
            NEXT(loc) = p;
        }
    }
}

void insertAt_linked_list(List *l, ElType val, int idx){
    int cnt = 0;
    Address p, loc;
    if(idx == 0){
        insertFirst_linked_list(l, val);
    }
    else{
        p = newNode(val);
        if(p != NULL){
            loc = *l;
            while(cnt < idx-1){
                cnt += 1;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst_linked_list(List *l, ElType *val){
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast_linked_list(List *l, ElType *val){
    Address p = FIRST(*l);
    Address loc = NULL;
    while(NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if(loc == NULL){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt_linked_list(List *l, int idx, ElType *val){
    if(idx == 0){
        deleteFirst_linked_list(l, val);
    }
    else{
        int cnt = 0;
        Address p, loc;
        loc = FIRST(*l);
        while(cnt < idx - 1){
            cnt += 1;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList_linked_list(List l){
    Address p = FIRST(l);
    if (isEmpty_linked_list(l)){
        printf("[]");
    }
    else{
        printf("[");
        while(p != NULL){
            if(NEXT(p) == NULL){
                printf("%i", INFO(p));
            }
            else{
                printf("%i,", INFO(p));
            }
            p = NEXT(p);
        }
        printf("]");
    }
}

int length_linked_list(List l){
    Address p = FIRST(l);
    int cnt = 0;
    if(isEmpty_linked_list(l)){
        return cnt;
    }
    else{
        while(p != NULL){
            cnt += 1;
            p = NEXT(p);
        }
    }
    return cnt;
}
