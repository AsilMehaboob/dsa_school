#include<stdio.h>
#define n 5

int queue[n],rear=-1,front=-1;

void enqueue(int data)
{
    if(rear==n-1)
        printf("Overflow");
    else if(rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}

void dequeue()
{
    int data;
    if(front==-1)
        printf("Underflow");
    else if(front==rear)
    {
        data=queue[front];
        front=rear=-1;
    }
    else
    {
        data=queue[front];
        front++;
    }
}

void display()
{
    if(front==-1)
        printf("Empty");
    else    
    {
        for(int i=front;i<=rear;i++)
            printf("%d",queue[i]);
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