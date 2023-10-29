#ifndef MATRIX_H
#define MATRIX_H

#include "boolean.h"

#define ROW_CAPACITY 20
#define COL_CAPACITY 20

#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELEMENT(M, i, j) (M).mem[(i)][(j)]


typedef int Index_Type;
typedef int Elmt_Type;
typedef struct
{
   ElType mem[ROW_CAPACITY][COL_CAPACITY];
   int rowEFF;
   int colEFF;
} Matrix;


void create_matrix(int nRows, int nCols, Matrix *m);

boolean is_matrix_valid(int i, int j);

Index_Type get_lastIdxRow_matrix(Matrix m);

Index_Type get_lastIdxCol_matrix(Matrix m);

boolean isIdxEff_matrix(Matrix m, Index_Type i, Index_Type j);

Elmt_Type get_elmtDiagonal_matrix(Matrix m, Index_Type i);


void copy_matrix(Matrix mIn, Matrix *mOut);


Matrix read_matrix(Matrix *m, int nRow, int nCol);

void display_matrix(Matrix m);


Matrix add_matrix(Matrix m1, Matrix m2);

Matrix subtract_matrix(Matrix m1, Matrix m2);

Matrix multiply_matrix(Matrix m1, Matrix m2);

Matrix multiply_matrix_mod(Matrix m1,Matrix m2,int mod);

Matrix mMultiply_matrix_const(Matrix m, Elmt_Type x);

void vMultiply_matrix_const(Matrix *m, Elmt_Type k);


boolean is_matrix_equal(Matrix m1, Matrix m2);

boolean is_matrix_not_equal(Matrix m1, Matrix m2);

boolean is_matrix_size_equal(Matrix m1, Matrix m2);


int count_elmt(Matrix m);


boolean is_matrix_square(Matrix m);

boolean is_matrix_symmetric(Matrix m);

boolean is_matrix_identity(Matrix m);

boolean is_matrix_sparse(Matrix m);

Matrix mNegation_matrix(Matrix m);

void vNegation_matrix(Matrix *m);

float determinant_matrix(Matrix m);

Matrix mTranspose_matrix(Matrix m);

void vTranspose_matrix(Matrix *m);

#endif
