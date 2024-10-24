#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

struct node *prev=NULL;


struct node *create(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
}


void insertfront(int data)
{
    struct node *newnode = create(data);
    newnode->next=head;
    head=newnode;
}

void insertend(int data)
{
    struct node *newnode=create(data);
    struct node *temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insertspecific(int data,int pos)
{
    struct node *newnode=create(data);
    if(pos==0)
    {
        insertfront(data);
    }
    else 
    {
        struct node *temp=head;
        for(int i=0;temp!=NULL&&i<pos-1;i++)
        {
            temp=temp->next;
        }

        if(temp==NULL)
            printf("Out of Bounds");
        else
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}

void deletefront()
{
    if(head==NULL)
    {
        printf("Empty");
    }
    else
    {
         struct node *temp=head;
        head=head->next;
        free(temp);
    }
}

void deleteend()
{

    if(head==NULL)
    {
        printf("Empty");
    }
    else
    {
        struct node *temp=head;
        prev=NULL;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
    prev->next=NULL;
    free(temp);

    }
}

void deletespecific(int pos)
{
    if(head==NULL)
        printf("Empty");
    if(pos==0)
        deletefront();
    else
    {
        struct node *temp=head;
        prev=NULL;
        for(int i=0;i<pos&&temp!=NULL;i++)
        {
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL)
            printf("Out of Bounds");
        else
        {
            prev->next=temp->next;
            free(temp);
        }
    }
}



void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete from specific position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertfront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertend(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertspecific(data, pos);
                break;
            case 4:
                deletefront();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletespecific(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}