#include<stdio.h>
int a[100][3],b[100][3];

void sparse(int sr[100][3])
{
    int i,j,k;

    printf("Enter rows");
    scanf("%d",&sr[0][0]);
    printf("Enter cols");
    scanf("%d",&sr[0][1]);
    printf("Enter total number of non-zeroes");
    scanf("%d",&sr[0][2]);

    for(i=1;i<=sr[0][2];i++)
    {
        printf("Enter row column value:");
            for(j=0;j<3;j++)
                scanf("%d",&sr[i][j]);
    }

    printf("Sparse Representation\n");
    for(k=0;k<=sr[0][2];k++)
        {
                for(j=0;j<3;j++)
                    printf("%d\t",sr[k][j]);
                printf("\n");
        }
}


void transpose(int a[100][3])
{
    int m,n,i,j,k;
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    k=1;
    for(i=0;i<a[0][1];i++)
        {
            for(j=0;j<=a[0][2];j++)
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

    printf("\nTranspose\n");
    for(k=0;k<=b[0][2];k++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",b[k][j]);
        printf("\n");
    }
}


int main()
{
    sparse(a);
    transpose(a);
    return 0;
}