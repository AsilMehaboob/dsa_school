#include <stdio.h>

int create(int m, int n, int T[][3]) {
    int k = 1, e;
    T[0][0] = m;
    T[0][1] = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &e);
            if (e != 0) {
                T[k][0] = i;
                T[k][1] = j;
                T[k][2] = e;
                k++;
            }
        }
    }
    T[0][2] = k;  // Store the number of non-zero elements
    return k;
}

void display(int k, int T[][3]) {
    for (int i = 0; i < k; i++) 
        printf("%d\t%d\t%d\n", T[i][0], T[i][1], T[i][2]);
    
}

int add(int m, int n, int k1, int k2, int T1[][3], int T2[][3], int T3[][3]) {
    int i = 1, j = 1, k = 1;  // Start indices from 1
    T3[0][0] = m;
    T3[0][1] = n;

    while (i < k1 && j < k2) {
        if (T1[i][0] == T2[j][0]) {
            if (T1[i][1] == T2[j][1]) {
                T3[k][0] = T1[i][0];
                T3[k][1] = T1[i][1];
                T3[k][2] = T1[i][2] + T2[j][2];
                i++;
                j++;
            } else if (T1[i][1] < T2[j][1]) {
                T3[k][0] = T1[i][0];
                T3[k][1] = T1[i][1];
                T3[k][2] = T1[i][2];
                i++;
            } else {
                T3[k][0] = T2[j][0];
                T3[k][1] = T2[j][1];
                T3[k][2] = T2[j][2];
                j++;
            }
            k++;
        } else if (T1[i][0] < T2[j][0]) {
            T3[k][0] = T1[i][0];
            T3[k][1] = T1[i][1];
            T3[k][2] = T1[i][2];
            i++;
            k++;
        } else {
            T3[k][0] = T2[j][0];
            T3[k][1] = T2[j][1];
            T3[k][2] = T2[j][2];
            j++;
            k++;
        }
    }

    while (i < k1) {
        T3[k][0] = T1[i][0];
        T3[k][1] = T1[i][1];
        T3[k][2] = T1[i][2];
        i++;
        k++;
    }

    while (j < k2) {
        T3[k][0] = T2[j][0];
        T3[k][1] = T2[j][1];
        T3[k][2] = T2[j][2];
        j++;
        k++;
    }

    T3[0][2] = k;  // Store the number of non-zero elements in the result
    return k;
}

int main() {
    int rows1, cols1, rows2, cols2, k1, k2, k3;
    int T1[50][3], T2[50][3], T3[50][3];

    printf("Enter the number of rows and columns of the first matrix (rows cols): ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns of the second matrix (rows cols): ");
    scanf("%d %d", &rows2, &cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix addition is not possible.\n");
        return 0;
    }

    printf("Enter Matrix 1: \n");
    k1 = create(rows1, cols1, T1);
    printf("Matrix 1:\n");
    display(k1, T1);

    printf("Enter Matrix 2: \n");
    k2 = create(rows2, cols2, T2);
    printf("Matrix 2:\n");
    display(k2, T2);

    printf("ADD: \n");
    k3 = add(rows1, cols1, k1, k2, T1, T2, T3);
    printf("Result:\n");
    display(k3, T3);

    return 0;
}
