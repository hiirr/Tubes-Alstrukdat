#include "../ADT/GraphMatrix.h"
#include <stdio.h>
#include <assert.h>

int main() {
    GraphMatrix myGraph;

    create_graph_matrix(&myGraph, 5, 5);
    assert(myGraph.row == 5 && myGraph.col == 5);

    for (int i = 0; i < myGraph.row; i++) {
        for (int j = 0; j < myGraph.col; j++) {
            assert(myGraph.matrix[i][j] == 0);
        }
    }

    add_relation(&myGraph, 1, 2);
    assert(myGraph.matrix[1][2] == 1 && myGraph.matrix[2][1] == 1);

    delete_relation(&myGraph, 1, 2);
    assert(myGraph.matrix[1][2] == 0 && myGraph.matrix[2][1] == 0);

    printf("All tests passed successfully.\n");

    return 0;
}
