#include<stdio.h>
#define n 4

int stack[n],top=-1;

void push(int data)
{
    if(top==n-1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top]=data;
    }
}

void pop()
{
    int data;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        data=stack[top];
        top--;
    }
}

void display()
{
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        for(int i=0;i<=top;i++)
            printf("%d",stack[i]);
    }
}


void peak()
{
    if(top==-1)
        printf("Empty");
    else
    {
        printf("Top:%d",stack[top]);
    }
}
void main()
{
    int choice,data;

    do
    {
        printf("1.Push 2.Pop 3.Display 4.Peak");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1: printf("element:"); 
                    scanf("%d",&data); 
                    push(data); 
                    break;
            case 2: pop(); 
                    break;
            case 3: display(); 
                    break;
            case 4: peak(); 
                    break;
            

        }
    }while(choice!=4);
}