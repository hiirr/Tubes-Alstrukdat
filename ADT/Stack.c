#include "Stack.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
    return Top(S) == Nil;
}

boolean IsFull(Stack S){
    return Top(S) == MaxEl - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X){
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X){
    *X = InfoTop(*S);
    Top(*S)--;
}