#include<stdio.h>
#include<stdlib.h>

struct queue
{
  int *a;
  int size;
  int front;
  int rear;		
};


struct queue* new_queue(int max_size)
{
	struct queue *q;
	q=(struct queue*)malloc(sizeof(struct queue));
	q->front=0;
	q->rear=-1;
    (q->a)=(int*)malloc(sizeof(int)*max_size);
    return q;
}

void enqueue(struct queue *q,int data,int max_size)
{
	if(q->size==(max_size)) printf("OVERFLOW\n");
	else
	{
         q->rear=(q->rear+1)%max_size;   
	 q->a[q->rear]=data;
	 q->size=(q->size)+1;
	}	
}

void dequeue(struct queue *q,int max_size)
{
	
	 if(q->size==0) printf("EMPTY\n");
	 
	 else
	   {
		printf("%d ",q->a[q->front]);
		q->front=(q->front+1)%max_size;
		q->size=(q->size)-1;
	   }
}
	
void print(struct queue *q,int max_size)
{
	if((q->size)==0)  printf("EMPTY\n");
	else
	{
		int i;
		for( i = q->front; i!=q->rear; i=(i+1)%max_size)
              {
                printf("%d ",q->a[i]);
              }
             printf("%d\n",q->a[q->rear]);
	}
	
}

int main()
{
	int n;
        int max_size;
	printf("Enter the size of queue ");
	scanf("%d",&max_size);
	struct queue *q1=new_queue(max_size); 
	while(1)
	{
		printf("Enter operation ");
		scanf("%d",&n);
		int a;
		if(n==1)
		{
			printf("Enter the element to be inserted ");
			scanf("%d",&a);
			enqueue(q1,a,max_size);
		}
		if(n==2)
		dequeue(q1,max_size);
		
		if(n==3)
		 print(q1,max_size);
		 
		if(n==4) break; 
	}
	
}

