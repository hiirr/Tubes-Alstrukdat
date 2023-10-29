#include <stdio.h>
#include "matrix.h"

void create_matrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            ELEMENT(*m, i, j) = 0;
        }
    }
}

boolean is_matrix_valid(int i, int j){
    return (i >= 0 && i < ROW_CAPACITY && j >= 0 && j < COL_CAPACITY);
}

Index_Type get_lastIdxRow_matrix(Matrix m){
    return ROW_EFF(m) - 1;
}

Index_Type get_lastIdxCol_matrix(Matrix m){
    return COL_EFF(m) - 1;
}

boolean isIdxEff_matrix(Matrix m, Index_Type i, Index_Type j){
    return (i >= 0 && i <= getLastIdxRow(m) && j >= 0 && j < getLastIdxCol(m));
}

ElType get_elmtDiagonal_matrix(Matrix m, Index_Type i){
    return ELEMENT(m, i, i);
}


void copy_matrix(Matrix mIn, Matrix *mOut){
    create_matrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for(int i = 0; i < ROW_EFF(mIn); i++){
        for(int j = 0; j < COL_EFF(mIn); j++){
            ELEMENT(*mOut, i, j) = ELEMENT(mIn, i, j);
        }
    }
}


Matrix read_matrix(Matrix *m, int nRow, int nCol){
    if (is_matrix_valid(nRow-1, nCol-1)){
        create_matrix(nRow, nCol, m);
        for(int i = 0; i < nRow; i++){
            for(int j = 0; j < nCol; j++){
                scanf("%d", &ELEMENT(*m, i, j));
            }
        }
    }
    return m;


}

void display_matrix(Matrix m){
    for(int i = 0; i < ROW_EFF(m); i++){
       for(int j = 0; j < COL_EFF(m); j++){
            if (j < COL_EFF(m) - 1){
                printf("%d ", ELEMENT(m, i, j));
            } else {
                printf("%d\n", ELEMENT(m, i, j));
            }
       }
    }
}


Matrix add_matrix(Matrix m1, Matrix m2){
    Matrix m3;
    create_matrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for(int i = 0; i < ROW_EFF(m1); i++){
        for(int j = 0; j < COL_EFF(m1); j++){
            ELEMENT(m3, i, j) = ELEMENT(m1, i, j) + ELEMENT(m2, i, j);
        }
    }
    return m3;
}

Matrix subtract_matrix(Matrix m1, Matrix m2){
    Matrix m3;
    create_matrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for(int i = 0; i < ROW_EFF(m1); i++){
        for(int j = 0; j < COL_EFF(m1); j++){
            ELEMENT(m3, i, j) = ELEMENT(m1, i, j) - ELEMENT(m2, i, j);
        }
    }
    return m3;
}

Matrix multiply_matrix(Matrix m1, Matrix m2){
    Matrix m3;
    create_matrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for(int i = 0; i < ROW_EFF(m1); i++){
        for(int j = 0; j < COL_EFF(m2); j++){
            for(int k = 0; k < COL_EFF(m1); k++){
                ELEMENT(m3, i, j) += ELEMENT(m1, i, k) * ELEMENT(m2, k, j);
            }
        }
    }
    return m3;
}

Matrix multiply_matrix_mod(Matrix m1,Matrix m2,int mod){
    Matrix m3;
    create_matrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    for(int i = 0; i < ROW_EFF(m1); i++){
        for(int j = 0; j < COL_EFF(m2); j++){
            for(int k = 0; k < COL_EFF(m1); k++){
                ELEMENT(m3, i, j) += ELEMENT(m1, i, k) * ELEMENT(m2, k, j);
            }
            ELEMENT(m3, i, j) %= mod;
        }
    }
    return m3;
}

Matrix mMultiply_matrix_const(Matrix m, ElType x){
    Matrix mX;
    create_matrix(ROW_EFF(m), COL_EFF(m), &mX);
    for(int i = 0; i < ROW_EFF(m); i++){
        for(int j = 0; j < COL_EFF(m); j++){
            ELEMENT(mX, i, j) = ELEMENT(m, i, j) * x;
        }
    }
    return mX;
}

void vMultiply_matrix_const(Matrix *m, ElType k){
    for(int i = 0; i < ROW_EFF(*m); i++){
        for(int j = 0; j < COL_EFF(*m); j++){
            ELEMENT(*m, i, j) *= k;
        }
    }
}


boolean is_matrix_equal(Matrix m1, Matrix m2){
    if (ROW_EFF(m1) != ROW_EFF(m2) || COL_EFF(m1) != COL_EFF(m2)) {
        return false;
    }
    for(int i = 0; i < ROW_EFF(m1); i++){
        for(int j = 0; j < COL_EFF(m1); j++){
            if (ELEMENT(m1, i, j) != ELEMENT(m2, i, j)){
                return false;
            }
        }
    }
    return true;
}

boolean is_matrix_not_equal(Matrix m1, Matrix m2){
    return (!(is_matrix_equal(m1, m2)));
}

boolean is_matrix_size_equal(Matrix m1, Matrix m2){
    return (COL_EFF(m1) == COL_EFF(m2) && ROW_EFF(m1) == ROW_EFF(m2));
}


int count_elmt(Matrix m){
    return (ROW_EFF(m) * COL_EFF(m));
}


boolean is_matrix_square(Matrix m){
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean is_matrix_symmetric(Matrix m){
    if (!(is_matrix_square(m))) {
        return false;
    }
    for(int i = 0; i < ROW_EFF(m); i++){
        for(int j = 0; j < COL_EFF(m); j++){
            if (ELEMENT(m, i, j) != ELEMENT(m, j, i)){
                return false;
            }
        }
    }
    return true;
}

boolean is_matrix_identity(Matrix m){
    if (!(is_matrix_square(m))) {
        return false;
    }
    for(int i = 0; i < ROW_EFF(m); i++){
        for(int j = 0; j < COL_EFF(m); j++){
            if ( i == j && ELEMENT(m, i, j) != 1){
                return false;
            } else if (i != j && ELEMENT(m, i, j) != 0){
                return false;
            }
        }
    }
    return true;
}

boolean is_matrix_sparse(Matrix m){
    float now = 0;
    for(int i = 0; i < ROW_EFF(m); i++){
        for(int j = 0; j < COL_EFF(m); j++){
            if (ELEMENT(m, i, j) != 0){
                now ++;
            }
        }
    }
    return (now <= (count_elmt(m)*5/100));
}

Matrix mNegation_matrix(Matrix m){
    Matrix n;
    create_matrix(ROW_EFF(m), COL_EFF(m), &n);
    for(int i = 0; i < ROW_EFF(m); i++){
        for(int j = 0; j < COL_EFF(m); j++){
            ELEMENT(n, i, j) = ELEMENT(m, i, j) * -1;
        }
    }
    return n;
}

void vNegation_matrix(Matrix *m){
    for(int i = 0; i < ROW_EFF(*m); i++){
        for(int j = 0; j < COL_EFF(*m); j++){
            ELEMENT(*m, i, j) *= -1;
        }
    }
}

float determinant_matrix(Matrix m){\
    int n = get_lastIdxRow_matrix(m) + 1;
    int tmpRow[11];
    int i, j, k, idx, temp1, temp2;
    int det = 1;
    int total = 1;
    for (i = 0; i < n; i++) {
        idx = i;
        while((ELEMENT(m, idx, i) == 0) && (idx < n)) {
            idx++;
        }
        if (idx == n) {
            return 0;
        }
        if (i != idx) {
            for (j = 0; j < n; j++) {
                temp1 = ELEMENT(m, i, j);
                ELEMENT(m, i, j) = ELEMENT(m, idx, j);
                ELEMENT(m, idx, j) = temp1;
            }
            det *= -1;
        }
        for(j = 0; j < n; j++) {
            tmpRow[j] = ELEMENT(m, i, j);
        }
        for (j = i + 1; j < n; j++) {
            temp1 = tmpRow[i];
            temp2 = ELEMENT(m,j,i);
            for (k = 0; k < n; k++){
                ELEMENT(m, j, k) = ((temp1 * ELEMENT(m,j,k)) - (temp2 * tmpRow[k]));
            }
            total *= temp1;
        }
    }
    for (i = 0; i < n; i++){
        det *= ELEMENT(m, i, i);
    }
    return (det/total);
}

Matrix mTranspose_matrix(Matrix m){
    Matrix t;
    create_matrix(COL_EFF(m), ROW_EFF(m), &t);
    for(int i = 0; i < ROW_EFF(m); i++){
        for(int j = 0; j < COL_EFF(m); j++){
            ELEMENT(t, i, j) = ELEMENT(m, j, i);
        }
    }
    return t;
}

void vTranspose_matrix(Matrix *m){
    for(int i = 0; i < ROW_EFF(*m); i++){
        for(int j = i + 1; j < COL_EFF(*m); j++){
            int temp = ELEMENT(*m, i, j);
            ELEMENT(*m, i, j) = ELEMENT(*m, j, i);
            ELEMENT(*m, j, i) = temp;
        }
    }
}
