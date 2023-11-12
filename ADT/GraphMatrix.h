#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include "boolean.h"

#define ROW_CAPACITY 20
#define COL_CAPACITY 20

typedef struct GraphMatrix {
   int matrix[ROW_CAPACITY][COL_CAPACITY];
   int row;
   int col;
} GraphMatrix;

void create_graph_matrix(GraphMatrix *m, int row, int col);

void print_graph_matrix(GraphMatrix *m);

void add_relation(GraphMatrix *m, int row, int col);

void delete_relation(GraphMatrix *m, int row, int col);

#endif
