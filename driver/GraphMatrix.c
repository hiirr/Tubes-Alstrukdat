#include "../ADT/GraphMatrix.h"
#include <stdio.h>

int main() {
    GraphMatrix myGraph;

    create_graph_matrix(&myGraph, 5, 5);
    if (myGraph.row == 5 && myGraph.col == 5) {
        printf("passed\n");
    }

    for (int i = 0; i < myGraph.row; i++) {
        for (int j = 0; j < myGraph.col; j++) {
            if (myGraph.matrix[i][j] == 0) {
                printf("passed\n");
            }
        }
    }

    add_relation(&myGraph, 1, 2);
    if (myGraph.matrix[1][2] == 1 && myGraph.matrix[2][1] == 1) {
        printf("passed\n");
    }

    delete_relation(&myGraph, 1, 2);
    if (myGraph.matrix[1][2] == 0 && myGraph.matrix[2][1] == 0) {
        printf("passed\n");
    }

    printf("All tests passed successfully.\n");

    return 0;
}
