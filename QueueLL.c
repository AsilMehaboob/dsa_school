#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    if(front==NULL&&rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
    struct node *temp=front;
    if(temp==NULL)
        printf("Empty");
    else
    {
        printf("deleted:%d",temp->data);
        front=front->next;
        free(temp);
    }
}

void display()
{   
    struct node *temp=front;
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
        printf("1.Push 2.Pop 3.Display ");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1: printf("element:"); 
                    scanf("%d",&data); 
                    enqueue(data); 
                    break;
            case 2: dequeue(); 
                    break;
            case 3: display(); 
                    break;
            

        }
    }while(choice!=4);
}