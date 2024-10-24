#include <stdio.h>

void transpose(int sparse[][3], int t, int result[][3]);

int main() {
    // Sample sparse matrix with 2 rows (1 non-zero element each) and a dimension of 3x3
    int sparse[4][3] = {
        {3, 3, 2}, // 3 rows, 3 columns, 2 non-zero elements
        {0, 0, 1}, // Row 0, Column 0, Value 1
        {1, 2, 2}  // Row 1, Column 2, Value 2
    };
    
    int result[4][3]; // To hold the transposed matrix
    transpose(sparse, 2, result);

    // Print the transposed sparse matrix
    for (int i = 0; i < 4; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}

void transpose(int sparse[][3], int t, int result[][3]) {
    result[0][0] = sparse[0][1]; // number of rows
    result[0][1] = sparse[0][0]; // number of columns
    result[0][2] = sparse[0][2]; // number of non-zero elements
    int k = 1; // Start from the second row of result
    
    for (int i = 0; i < sparse[0][0]; i++) {
        for (int j = 1; j <= t; j++) {
            if (sparse[j][1] == i) {
                result[k][0] = sparse[j][1]; // Transpose row index
                result[k][1] = sparse[j][0]; // Transpose column index
                result[k][2] = sparse[j][2]; // Keep value
                k++;
            }
        }
    }
}
