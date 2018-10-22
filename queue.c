#include<stdio.h>
#include<stdlib.h>
#define MAX 100001

struct queue
{
  int a[MAX];
  int size;
  int front;
  int rear;		
};

int max_size;
struct queue* new_queue()
{
	struct queue *q;
	q=(struct queue*)malloc(sizeof(struct queue));
	q->front=0;
	q->rear=0;
    
    return q;
}

void enqueue(struct queue *q,int data)
{
	if(q->size==(max_size)) printf("OVERFLOW\n");
	else
	{
	q->a[q->rear]=data;
	q->size=(q->size)+1;
	q->rear=q->rear+1;
	}	
}

void dequeue(struct queue *q)
{
	
	 if(q->size==0) printf("EMPTY\n");
	 
	 else
	   {
		printf("%d ",q->a[q->front]);
		q->front=q->front+1;
		q->size=(q->size)-1;
	   }
}
	
void print(struct queue *q)
{
	if((q->size)==0)  printf("EMPTY\n");
	else
	{
		int i;
		for(i=q->front;i<(q->rear);i++)
		{
			printf("%d ",(q->a[i]));
		}
	}
	
}

int main()
{
	int n;

	printf("Enter the size of queue ");
	scanf("%d",&max_size);
	struct queue *q1=new_queue(); 
	while(1)
	{
		printf("Enter operation ");
		scanf("%d",&n);
		int a;
		if(n==1)
		{
			printf("Enter the element to be inserted ");
			scanf("%d",&a);
			enqueue(q1,a);
		}
		if(n==2)
		dequeue(q1);
		
		if(n==3)
		 print(q1);
		 
		if(n==4) break; 
	}
	
}

