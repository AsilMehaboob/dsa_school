#include<stdio.h>

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

int add(int sparse1[][3],int sparse2[][3],int t1,int t2,int sparse3[][3])
{
    int i=1;j=1;k=0;
    sparse[0][0]=sparse1[0][1];
    sparse[0][2]=sparse1[0][2];
    while(i<t1&&j<t2)
    {
    if(sparse1[i][0]==sparse2[j][0])
    {  
        if(sparse1[i][1]==sparse2[j][1])
        {
            k++;
            sparse3[k][0]=sparse1[i][0];
            sparse3[k][1]=sparse1[i][1];
            sparse3[k][2]=sparse1[i][2]+sparse2[j][2];
            i++;
            j++;
        }
        else if(sparse1[i][1]<sparse2[j][1])
        {
            k++;
            sparse3[k][0]=sparse1[i][0];
            sparse3[k][1]=sparse1[i][1];
            sparse3[k][2]=sparse1[i][2];
            i++;
        }
        else
        {
            k++;
            sparse3[k][0]=sparse2[j][0];
            sparse3[k][1]=sparse2[j][1];
            sparse3[k][2]=sparse2[j][2];
            j++;
        }
    }
    else if(sparse1[i][0]<sparse2[j][0])
    {
        k++;
        sparse3[k][0]=sparse1[i][0];
        sparse3[k][1]=sparse1[i][1];
        sparse3[k][2]=sparse1[i][2];
        i++;
    }
    else
    {
        k++;
        sparse3[k][0]=sparse2[j][0];
        sparse3[k][1]=sparse2[j][1];
        sparse3[k][2]=sparse2[j][2];
        j++;
    }
    }
    while(i<t1)
    {
        k++;
        sparse3[k][0]=sparse1[i][0];
        sparse3[k][1]=sparse1[i][1];
        sparse3[k][2]=sparse1[i][2];
        i++;
    }
    while(j<t2)
    {
        k++;
        sparse3[k][0]=sparse2[j][0];
        sparse3[k][1]=sparse2[j][1];
        sparse3[k][2]=sparse2[j][2];
        j++;
    }
}

void display