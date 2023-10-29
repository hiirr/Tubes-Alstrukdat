#include "Matrix.h"
#include <stdio.h>

int main(){
   Matrix m, me;
   int i, j, k, baris, kolom;
   float det;
   scanf("%d\n", &baris);
   scanf("%d\n", &kolom);
   create_matrix(baris, kolom, &m);
   read_matrix(&m, baris, kolom);
   display_matrix(m);
}