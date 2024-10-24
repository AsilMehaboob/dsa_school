#include<stdio.h>

// Function to create a sparse matrix
int create(int sparse[][3], int r, int c) {
    int val;
    int k = 1;  // Start with 1, since the first row will store metadata (rows, columns, non-zero elements)
    sparse[0][0] = r;  // Number of rows
    sparse[0][1] = c;  // Number of columns

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("Enter value at (%d,%d): ", i, j);
            scanf("%d", &val);
            if(val != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = val;
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;  // Total number of non-zero elements
    return k;
}

// Function to add two sparse matrices
int add(int sparse1[][3], int sparse2[][3], int t1, int t2, int sparse3[][3]) {
    int i = 1, j = 1, k = 1;

    // Initialize the result matrix's metadata
    sparse3[0][0] = sparse1[0][0];  // Number of rows
    sparse3[0][1] = sparse1[0][1];  // Number of columns

    while(i < t1 && j < t2) {
        if(sparse1[i][0] == sparse2[j][0]) {
            if(sparse1[i][1] == sparse2[j][1]) {
                sparse3[k][0] = sparse1[i][0];
                sparse3[k][1] = sparse1[i][1];
                sparse3[k][2] = sparse1[i][2] + sparse2[j][2];
                i++;
                j++;
            } else if(sparse1[i][1] < sparse2[j][1]) {
                sparse3[k][0] = sparse1[i][0];
                sparse3[k][1] = sparse1[i][1];
                sparse3[k][2] = sparse1[i][2];
                i++;
            } else {
                sparse3[k][0] = sparse2[j][0];
                sparse3[k][1] = sparse2[j][1];
                sparse3[k][2] = sparse2[j][2];
                j++;
            }
        } else if(sparse1[i][0] < sparse2[j][0]) {
            sparse3[k][0] = sparse1[i][0];
            sparse3[k][1] = sparse1[i][1];
            sparse3[k][2] = sparse1[i][2];
            i++;
        } else {
            sparse3[k][0] = sparse2[j][0];
            sparse3[k][1] = sparse2[j][1];
            sparse3[k][2] = sparse2[j][2];
            j++;
        }
        k++;
    }

    // Add remaining elements of sparse1
    while(i < t1) {
        sparse3[k][0] = sparse1[i][0];
        sparse3[k][1] = sparse1[i][1];
        sparse3[k][2] = sparse1[i][2];
        i++;
        k++;
    }

    // Add remaining elements of sparse2
    while(j < t2) {
        sparse3[k][0] = sparse2[j][0];
        sparse3[k][1] = sparse2[j][1];
        sparse3[k][2] = sparse2[j][2];
        j++;
        k++;
    }

    sparse3[0][2] = k - 1;  // Total number of non-zero elements
    return k;
}

// Function to display a sparse matrix
void display(int sparse[][3]) {
    int total_non_zero = sparse[0][2];
    printf("Row\tColumn\tValue\n");
    for(int i = 0; i <= total_non_zero; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int sparse1[100][3], sparse2[100][3], sparse3[100][3];
    int r1, c1, r2, c2;

    // Input dimensions for first matrix
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    int t1 = create(sparse1, r1, c1);  // Create first sparse matrix

    // Input dimensions for second matrix
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);
    if (r1 != r2 || c1 != c2) {
        printf("Matrices must have the same dimensions to add!\n");
        return 1;
    }

    int t2 = create(sparse2, r2, c2);  // Create second sparse matrix

    // Add the matrices
    int t3 = add(sparse1, sparse2, t1, t2, sparse3);

    // Display the result
    printf("\nFirst Sparse Matrix:\n");
    display(sparse1);

    printf("\nSecond Sparse Matrix:\n");
    display(sparse2);

    printf("\nResultant Sparse Matrix (Addition):\n");
    display(sparse3);

    return 0;
}
