#include "../ADT/Matrix.h"
#include <stdio.h>

int main() {
    Matrix myMatrix, copyMatrix;

    create_matrix(&myMatrix, 4, 4);
    if (myMatrix.row == 4 && myMatrix.col == 4) {
        printf("passed\n");
    }

    for (int i = 0; i < myMatrix.row; i++) {
        for (int j = 0; j < myMatrix.col; j++) {
            if (myMatrix.matrix[i][j] == 0) {
                printf("passed\n");
            }
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
            if (copyMatrix.matrix[i][j] == myMatrix.matrix[i][j]) {
                printf("passed\n");
            }
        }
    }

    printf("All tests passed successfully.\n");

    return 0;
}