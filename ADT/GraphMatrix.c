#include <stdio.h>
#include "GraphMatrix.h"

void create_graph_matrix(GraphMatrix *m, int row, int col) {
    m->row = row;
    m->col = col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            m->matrix[i][j] = 0;
        }
    }
}

void print_graph_matrix(GraphMatrix *m) {
    for(int i = 0; i < m->row; i++) {
       for(int j = 0; j < m->col; j++) {
            if (j < m->col - 1) {
                printf("%d ", m->matrix[i][j]);
            } else {
                printf("%d\n", m->matrix[i][j]);
            }
       }
    }
}

void add_relation(GraphMatrix *m, int row, int col) {
    m->matrix[row][col] = 1;
    m->matrix[col][row] = 1;
}

void delete_relation(GraphMatrix *m, int row, int col) {
    m->matrix[row][col] = 0;
    m->matrix[col][row] = 0;
}