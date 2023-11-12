#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include "boolean.h"

#define GRAPH_ROW_CAPACITY 20
#define GRAPH_COL_CAPACITY 20

typedef struct GraphMatrix {
   int matrix[GRAPH_ROW_CAPACITY][GRAPH_ROW_CAPACITY];
   int row;
   int col;
} GraphMatrix;

void create_graph_matrix(GraphMatrix *m, int row, int col);

void print_graph_matrix(GraphMatrix *m);

void add_relation(GraphMatrix *m, int row, int col);

void delete_relation(GraphMatrix *m, int row, int col);

#endif
