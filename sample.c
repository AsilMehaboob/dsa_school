#include <stdio.h>

int create(int sparse[][3], int r, int c) {
    int val;
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter value at (%d,%d):", i, j);
            scanf("%d", &val);
            if (val != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = val;
                k++;
            }
        }
    }
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = k - 1;
    return k;
}

int add(int sparse1[][3], int sparse2[][3], int t1, int t2, int sparse3[][3]) {
    int i = 1, j = 1, k = 1;
    sparse3[0][0] = sparse1[0][0];
    sparse3[0][1] = sparse1[0][1];
    sparse3[0][2] = 0;
    
    while (i < t1 && j < t2) {
        if (sparse1[i][0] == sparse2[j][0]) {
            if (sparse1[i][1] == sparse2[j][1]) {
                sparse3[k][0] = sparse1[i][0];
                sparse3[k][1] = sparse1[i][1];
                sparse3[k][2] = sparse1[i][2] + sparse2[j][2];
                k++;
                i++;
                j++;
            } else if (sparse1[i][1] < sparse2[j][1]) {
                sparse3[k][0] = sparse1[i][0];
                sparse3[k][1] = sparse1[i][1];
                sparse3[k][2] = sparse1[i][2];
                k++;
                i++;
            } else {
                sparse3[k][0] = sparse2[j][0];
                sparse3[k][1] = sparse2[j][1];
                sparse3[k][2] = sparse2[j][2];
                k++;
                j++;
            }
        } else if (sparse1[i][0] < sparse2[j][0]) {
            sparse3[k][0] = sparse1[i][0];
            sparse3[k][1] = sparse1[i][1];
            sparse3[k][2] = sparse1[i][2];
            k++;
            i++;
        } else {
            sparse3[k][0] = sparse2[j][0];
            sparse3[k][1] = sparse2[j][1];
            sparse3[k][2] = sparse2[j][2];
            k++;
            j++;
        }
    }
    while (i < t1) {
        sparse3[k][0] = sparse1[i][0];
        sparse3[k][1] = sparse1[i][1];
        sparse3[k][2] = sparse1[i][2];
        k++;
        i++;
    }
    while (j < t2) {
        sparse3[k][0] = sparse2[j][0];
        sparse3[k][1] = sparse2[j][1];
        sparse3[k][2] = sparse2[j][2];
        k++;
        j++;
    }
    sparse3[0][2] = k - 1;
    return k;
}

void display(int sparse[][3]) {
    int totalElements = sparse[0][2];
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= totalElements; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    int sparse1[100][3];
    int t1 = create(sparse1, r1, c1);
    display(sparse1);
    
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);
    int sparse2[100][3];
    int t2 = create(sparse2, r2, c2);
    display(sparse2);
    
    if (r1 != r2 || c1 != c2) {
        printf("Matrices cannot be added due to mismatched dimensions.\n");
        return 1;
    }
    
    int sparse3[100][3];
    int t3 = add(sparse1, sparse2, t1, t2, sparse3);
    
    printf("Resultant Sparse Matrix:\n");
    display(sparse3);
    
    return 0;
}
