#include "ADT\LinkedList.h"
#include <stdio.h>

int main(){
    List l;
    int val;
    create_linked_list(&l);
    if(isEmpty_linked_list(l)){
        printf("list kosong\n");
    }
    insertFirst_linked_list(&l, 1);
    insertLast_linked_list(&l, 2);
    insertAt_linked_list(&l, 3, 2);
    insertAt_linked_list(&l, 4, 3);
    displayList_linked_list(l);

    setElmt_linked_list(&l, 2, 10);
    printf("element ketiga: %i\n", getElmt_linked_list(l, 2));
    printf("indeks ke 0: %i\n", indexOf_linked_list(l, 0));
    printf("panjang list: %i\n", length_linked_list(l));

    deleteFirst_linked_list(&l, &val);
    displayList_linked_list(l);
    printf("\n");
    deleteAt_linked_list(&l, 1, &val);
    displayList_linked_list(l);
    printf("\n");
    deleteLast_linked_list(&l, &val);
    displayList_linked_list(l);
}