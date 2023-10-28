#include "..\ADT\Stack.h"
#include <stdio.h>

int main() {
    Stack S;
    infotype x;

    CreateEmpty(&S);

    if (IsEmpty(S)) {
        printf("stack kosong\n");
    }

    Push(&S, 10);
    Push(&S, 20);
    Push(&S, 30);

    if (IsFull(S)) {
        printf("stack penuh\n");
    }

    Pop(&S, &x);
    printf("elemen diambil: %d\n", x);

    Pop(&S, &x);
    printf("elemen diambil: %d\n", x);

    return 0;
}
