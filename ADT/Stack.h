#ifndef stackt_H
#define stackt_H

#include "../boolean.h"

#define Nil -1
#define MaxEl 100

typedef int infotype;
typedef int address;

typedef struct { 
  infotype T[MaxEl];
  address TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);

boolean IsFull(Stack S);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X);

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X);


#endif
