#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head=NULL;

struct node *tail=NULL;


struct node *create(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    return newnode;
}


void insertfront(int data)
{
    struct node *newnode = create(data);
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else{

    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    }
    
}

void insertrear(int data)
{
    struct node *newnode=create(data);
    if(head==NULL)
        head=tail=newnode;
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
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
            newnode->prev=temp;
            temp->next=newnode;
        }

        if(newnode->next!=NULL)
        {
            newnode->next->prev=newnode;
        }
    }
}

void deletefront()
{
    if(head==NULL)
    {
        printf("Empty");
    }

    if (head == tail) {
        // Only one element
        head = tail = NULL;
    } 

    else
    {
         struct node *temp=head;
         head->next->prev=NULL;
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

    if (head == tail) {
        // Only one element
        head = tail = NULL;
    } 

    else
    {
        struct node *temp=head;
        
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;
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
       
        for(int i=0;i<pos&&temp!=NULL;i++)
        {
            temp=temp->next;
        }

        
        
        if(temp->next!=NULL)
        {
            temp->next->prev=temp->prev;
        }
        

        if(temp->prev!=NULL)
        {
            temp->prev->next=temp->next;
        }
         free(temp);
        }
   
    }




void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertfront(10);
    insertrear(20);
    insertrear(30);
    insertfront(5);
    insertspecific(15, 2); // Insert 15 at position 2
    display();

    deletespecific(2); // Delete element at position 2
    display();

    deletefront();
    display();

    deleteend();
    display();

    return 0;
}