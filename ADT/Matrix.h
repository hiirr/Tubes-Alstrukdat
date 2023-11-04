#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"

#define ROW_CAPACITY 20
#define COL_CAPACITY 20


typedef struct Matrix {
   int matrix[ROW_CAPACITY][COL_CAPACITY];
   int row;
   int col;
} Matrix;


void create_matrix(Matrix *m, int row, int col);

void read_matrix(Matrix *m, int row, int col);

void print_matrix(Matrix *m);

void copy_matrix(Matrix *mIn, Matrix *mOut);

#endif
