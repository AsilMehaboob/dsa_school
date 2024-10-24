#include<stdio.h>
#define n 5

int dq[n],front=-1,rear=-1;

void insertf(int data)
{
    if((front==0&&rear==n-1)||(front==rear+1))
    {
        printf("Full");
    }
    else if(front==-1)
    {
        rear=front=0;
        dq[front]=data;
    }
    else if(front==0)
    {
        front=n-1;
        dq[front]=data;
    }
    else
    {
        front--;
        dq[front]=data;
    }
}


void insertr(int data)
{
    if((front==0&&rear==n-1)||(front==rear+1))
    {
        printf("Full");
    }
    else if(rear==-1)
    {
        rear=front=0;
        dq[rear]=data;
    }
    else if(rear==n-1)
    {
        rear=0;
        dq[rear]=data;
    }
    else
    {
        rear++;
        dq[rear]=data;
    }
}

void deletef()
{
    int data;
    if(front==-1)
    {
        printf("Underflow");
    }
    else if(front==rear)
    {
        data=dq[front];
        front=rear=-1;
    }
    else if(front==n-1)
    {
        data=dq[front];
        front=0;
    }
    else
    {
        data=dq[front];
        front++;
    }
}

void deleter()
{
    int data;
    if(front==-1)
    {
        printf("Underflow");
    }
    else if(front==rear)
    {
        data=dq[rear];
        front=rear=-1;
    }
    else if(rear==0)
    {
        data=dq[rear];
        rear=n-1;
    }
    else{
        data=dq[rear];
        rear--;
    }
}

void display()
{
    if(front==-1&&rear==-1)
        printf("EMPTY");
    else if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
            printf("%d",dq[i]);
    }
    else
    {
        for(int i=front;i<n;i++)
            printf("%d",dq[i]);
        for(int i=0;i<=rear;i++)
            printf("%d",dq[i]);
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &data);
                insertf(data);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &data);
                insertr(data);
                break;
            case 3:
                deletef();
                break;
            case 4:
                deleter();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}