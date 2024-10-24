#include<stdio.h>

struct poly
{
    float coeff;
    int exp;
};

struct poly p1[10],p2[10],p3[10];   
int ReadPoly(struct poly p[])
{
    int i,t1;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d",&t1);

    for(i=0;i<t1;i++)
    {
        printf("Enter the coefficient and exponent: ");
        scanf("%f %d",&p[i].coeff,&p[i].exp);
    }
    return t1;
}


void Display(struct poly p[],int t)
{
    int k=0;
    for(k=0;k<t-1;k++)
    {
        printf("%f(x^%d)+",p[k].coeff,p[k].exp);
    }
    printf("%f(x^%d)",p[t-1].coeff,p[t-1].exp);
};


int AddPoly(struct poly p1[],struct poly p2[],int t1,int t2,struct poly p3[])
{
    int i=0,j=0,k=0;
    while(i<t1&&j<t2)
    {
        if(p1[i].exp==p2[j].exp)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].exp=p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if(p1[i].exp>p2[j].exp)
        {
            p3[k].exp=p1[i].exp;
            p3[k].coeff=p1[i].coeff;
            i++;
            k++;
        }
        else
        {
            p3[k].exp=p2[j].exp;
            p3[k].coeff=p2[j].coeff;
            j++;
            k++;
        }
    }
    while (i<t1)
    {
        p3[k].exp=p1[i].exp;
        p3[k].coeff=p1[i].coeff;
        k++;
        i++;
    }
    while(j<t2)
    {
        p3[k].exp=p2[j].exp;
        p3[k].coeff=p2[j].coeff;
        k++;
        j++;
    }

    return k;
}


int main()
{
    int t1,t2,t3;

    printf("Polynomial 1");
    t1=ReadPoly(p1);
    Display(p1,t1);
    printf("Polynomial 2");
    t2=ReadPoly(p2);
    Display(p2,t2);
    printf("Add");
    t3=AddPoly(p1,p2,t1,t2,p3);
    Display(p3,t3);

    return 0;

}
