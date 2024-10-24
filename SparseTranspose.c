#include<stdio.h>

void transpose(int a[][3])
{
    int i,j,k=1;
    int b[100][3];

    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];

    for(i=0;i<a[0][1];i++)
    {
        for(j=0;j<a[0][2];j++)
        {
            if(a[j][1]==i)
            {
                b[k][0]=a[j][1];
                b[k][1]=a[j][0];
                b[k][2]=a[j][2];
                k++;
            }
        }
    }
// Display the transposed matrix
    printf("Transposed matrix in sparse format:\n");
    for(i = 0; i <= b[0][2]; i++)
    {
        printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
    }
}

int main()
{
    // Example sparse matrix: first row contains [rows, cols, non-zero elements]
    int a[4][3] = {
        {3, 3, 3},  // 3 rows, 3 columns, 3 non-zero elements
        {0, 1, 5},  // Non-zero element at (0,1) with value 5
        {1, 2, 8},  // Non-zero element at (1,2) with value 8
        {2, 0, 9}   // Non-zero element at (2,0) with value 9
    };

    transpose(a);

    return 0;
}
