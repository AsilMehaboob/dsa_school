#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}

void pop()
{
    struct node *temp=top;
    if(top==NULL)
    {
        printf("Empty");
    }
    else
    {
        printf("%d",temp->data);
        top=top->next;
        free(temp);
    }
}


void display()
{   
    struct node *temp=top;
    if(temp==NULL)
        printf("Underflow");
    else
    {
        while(temp!=NULL)
            {
                printf("%d\n",temp->data);
                temp=temp->next;
            }
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
            
            

        }
    }while(choice!=4);
}