#include<stdio.h>
#define N 20
int Q[N],Pr[N];
int r = -1,f = -1;
void enqueue(int data,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		printf("Queue is full");
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == N-1)//if there there is some elemets in Queue
		{
			for(i=f;i<=r;i++) { Q[i-f] = Q[i]; Pr[i-f] = Pr[i]; r = r-f; f = 0; for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else
						break;
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}
	}

}
void print() //print the data of Queue
{
int i;
	for(i=f;i<=r;i++)
	{
		printf("\nElement = %d\tPriority = %d",Q[i],Pr[i]);
	}
}
int dequeue() //remove the data from front
{
	if(f == -1)
	{
		printf("Queue is Empty")
	}
	else
	{
		printf("Deleted Element = %d\t Priority = %d",Q[f],Pr[f]);
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
int main()
{
	int opt,n,i,data,p;
	printf("Enter Your Choice:-");
	do{
		printf("\n 1 Insert the Data in Queue\n 2 Display the Data in Queue \n 3 Delete the data from the Queue\n 0 for Exit \n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the number of elements-");
				scanf("%d",&n);
				printf("\nEnter the data and Priority of data\n");
				i=0;
				while(i<n){
                    printf("Data-");
					scanf("%d",&data);
                    printf("Priority-");
                    scanf("%d",&p);
					enqueue(data,p);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");

		}
	}while(opt!=0);
        return 0;
}