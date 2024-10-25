#include<stdio.h>
#define n 5

int queue[n],rear=-1,front=-1;

void enqueue(int data)
{
    if((rear + 1) % n == front)
    {
        printf("Queue Overflow\n");
    }
    else if(rear == -1 && front == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear = (rear + 1) % n;
        queue[rear] = data;
    }
}

void dequeue()
{
    int data;
    if(front==-1&&rear==-1)
        printf("Underflow");
    else if(front==rear)
    {
        data=queue[front];
        front=rear=-1;
    }
    else
    {
        data=queue[front];
        front=(front+1)%n;
    }
}

void display() {
    if(front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } 
    else {
        printf("Queue elements: ");
        for(int i = front; i != rear; i = (i + 1) % n) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);  // Print the last element (rear)
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