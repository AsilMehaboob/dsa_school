#include<stdio.h>

void transpose(int sparse[][3],int t,int result[][3])
{
    result[0][0]=sparse[0][1];
    result[0][1]=sparse[0][0];
    result[0][2]=sparse[0][2];
    int k=1;
    for(int i=0;i<sparse[0][0];i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(sparse[j][1]==i)
            {
                result[k][0]=sparse[j][1];
                result[k][1]=sparse[j][0];
                result[k][2]=sparse[j][2];
                k++;
            }
        }
    }
}

void display(int sparse[][3],int k)
{
    printf("Sparse Representation:\n");
    for(int i=0;i<k;i++)
    {
        printf("%d%d%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
    }
}


int create(int sparse[][3],int r,int c)
{
    int val;
    int k=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Enter value at (%d,%d):",i,j);
            scanf("%d",&val);
            if(val!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=val;
                k++;
            }
        }
    }
    return k;
}


void main()
{
    int r,c,sparse[100][3],result[100][3],size;

    printf("Enter rows and cols:");
    scanf("%d%d",&r,&c);
    sparse[0][0]=r;
    sparse[0][1]=c;
    size=create(sparse,r,c);
    sparse[0][2]=size-1;
    display(sparse,size);
    transpose(sparse,size,result);
    printf("Transpose:\n");
    display(result,size);
}