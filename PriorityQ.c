#include<stdio.h>
#define n 5

struct pqueue
{
    int data;
    int priority;
};

struct pqueue pq[n];
int front=-1,rear=-1,loc,i;

void enqueue(int data,int priority)
{
    if(rear==n-1)
    {
        printf("OverFlow");
    }
    else 
    {if(front==-1)
    {
        front=rear=0;
        pq[rear].data=data;
        pq[rear].priority=priority;
    }
    else
    {
        int i;
        for(i=rear;i>=front&&pq[i].priority<=priority;i--)
        {
            pq[i+1]=pq[i];
        }
        pq[i+1].data=data;
        pq[i+1].priority=priority;
        rear++;
    }
    }
}

void dequeue()
{
    int data;
    if(front==-1)
        printf("Underflow");
    else if(front==rear)
    {

        front=rear=-1;
    }
    else
    {
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
            printf("%d(%d)",pq[i].data,pq[i].priority);
        printf("\n");
    }
}
void main()
{
    int choice,data,prio;

    do
    {
        printf("1.Push 2.Pop 3.Display ");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1: printf("element:"); 
                    scanf("%d",&data); 
                    printf("pri:"); 
                    scanf("%d",&prio); 
                    enqueue(data,prio); 
                    break;
            case 2: dequeue(); 
                    break;
            case 3: display(); 
                    break;
            

        }
    }while(choice!=4);
}