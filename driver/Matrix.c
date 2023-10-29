#include <stdio.h>
#include "ADT/Matrix.h"


int main() {
    Matrix m;
    create_matrix(&m, 3, 3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m.matrix[i][j] = 3 * i + j;
        }
    }
    print_matrix(&m);
}