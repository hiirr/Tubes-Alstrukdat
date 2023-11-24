#include "../ADT/Matrix.h"
#include <stdio.h>
#include <assert.h>

int main() {
    Matrix myMatrix, copyMatrix;

    create_matrix(&myMatrix, 4, 4);
    assert(myMatrix.row == 4 && myMatrix.col == 4);

    for (int i = 0; i < myMatrix.row; i++) {
        for (int j = 0; j < myMatrix.col; j++) {
            assert(myMatrix.matrix[i][j] == 0);
        }
    }

    for (int i = 0; i < myMatrix.row; i++) {
        for (int j = 0; j < myMatrix.col; j++) {
            myMatrix.matrix[i][j] = i + j;
        }
    }

    copy_matrix(&myMatrix, &copyMatrix);

    for (int i = 0; i < myMatrix.row; i++) {
        for (int j = 0; j < myMatrix.col; j++) {
            assert(copyMatrix.matrix[i][j] == myMatrix.matrix[i][j]);
        }
    }

    printf("All tests passed successfully.\n");

    return 0;
}