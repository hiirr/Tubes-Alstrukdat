#include <stdio.h>
#include "Matrix.h"

void create_matrix(Matrix *m, int row, int col) {
    m->row = row;
    m->col = col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            m->matrix[i][j] = 0;
        }
    }
}

void read_matrix(Matrix *m, int row, int col) {
    m->row = row;
    m->col = col;
    create_matrix(m, row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%c", m->matrix[i][j]);
        }
    }
}


void print_matrix(Matrix *m){
    for(int i = 0; i < m->row; i++){
       for(int j = 0; j < m->col; j++){
            if (j < m->col - 1){
                printf("%d ", m->matrix[i][j]);
            } else {
                printf("%d\n", m->matrix[i][j]);
            }
       }
    }
}

void copy_matrix(Matrix *mIn, Matrix *mOut){
    create_matrix(mOut, mIn->row, mIn->col);
    for(int i = 0; i < mIn->row; i++){
        for(int j = 0; j < mIn->col; j++){
            mIn->matrix[i][j] = mOut->matrix[i][j];
        }
    }
}
