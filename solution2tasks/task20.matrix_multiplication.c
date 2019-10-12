#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_col(int** m2, int column, int rows, int* target) {
    for (int i = 0; i < rows; i++) {
        target[i] = m2[i][column];
    }
}

int** multiply(int** m1, int** m2, int m1_r, int m1_c, int m2_c) {
    // m2_r == m1_c
    // Finally we get a matrix m1_r * m2_c
    int** matrix = (int**)malloc(sizeof(int*) * m1_r);
    // Initialize matrix
    for (int i = 0; i < m1_r; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * m2_c);
        memset(matrix[i], 0, sizeof(int) * m2_c);
    }

    int* column = (int*)malloc(sizeof(int) * m2_c);
    // We will calculate matrix row by row
    for (int j = 0; j < m1_r; j++) {
        // printf("%d", m2[0][j]);
        // Copy column j in m2 to column
        copy_col(m2, j, m1_c, column);
        for (int i = 0; i < m1_c; i++) {
            int temp = 0;
            int* m1_i = m1[i];
            for (int k = 0; k < m1_c; k++) {
                temp += column[k] * m1_i[k];
            }
            matrix[i][j] = temp;
        }
    }
    // m1_r * m2_c
    return matrix;
}

void print_matrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** init() {
    int row, column;
    scanf("%d%d", &row, &column);
    int** arr = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        arr[i] = (int*)malloc(sizeof(int) * column);
        for (int j = 0; j < column; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;
}

int main() {
    // int m1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    // int m2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int** m1 = init();
    int** m2 = init();
    int** res1 = multiply(m1, m2, 3, 3, 3);
    int** res2 = multiply(m2, m2, 3, 3, 3);
    print_matrix(res1, 3, 3);
    print_matrix(res2, 3, 3);
    free(res1);
    free(res2);
    free(m1);
    free(m2);
    return 0;
}
