#include<stdio.h>

int s[100][100],sr[100][100],r,c,i,j,k=1;

void sparse(int s[][100],int r,int c)
{
    sr[0][0]=r;
    sr[0][1]=c;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(s[i][j]!=0)
            {
                sr[k][0]=i;
                sr[k][1]=j;
                sr[k][2]=s[i][j];
                k++;
            }
        }
    }
    sr[0][2]=k-1;
    printf("Sparse Representation:\n");
    for(k=0;k<=sr[0][2];k++)
    {
        for(i=0;i<3;i++)
        {
            printf("%d\t",sr[k][i]);
        }
        printf("\n");
    }
}


void main()
{
    
    printf("Matrix");
    printf("Enter Rows and Cols:");
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    sparse(s,r,c);
}

