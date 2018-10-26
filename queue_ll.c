#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   	struct node *next;	
};

struct queue
{	
   struct node *front;
   struct node *rear;
};

struct queue* new_queue()
{
	struct queue *q=(struct queue*)malloc(sizeof(struct queue));
	q->front=NULL;
	q->rear=NULL;
	
	return q;
}

void enqueue(struct queue *q,int val)
{
	if(q->front==NULL||q->rear==NULL)
	{
		struct node *new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=val;
		new_node->next=NULL;
		q->front=new_node;
		q->rear=new_node;
	}
	else
	{
		struct node *new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=val;
		new_node->next=NULL;
		
		(q->rear)->next=new_node;
		q->rear=new_node;
	}
}

void dequeue(struct queue *q)
{
	if(q->front!=NULL)
	{
	printf("%d ",q->front->data);
	q->front=(q->front)->next;
    }
}

void print(struct queue *q)
{
	struct node *current=q->front;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}
	
}

int main()
{
	struct queue *q=new_queue();
	char ch;
	int a;
	while(1)
	{
	  scanf("%c",&ch);
	  if(ch=='e')
	  {
	    scanf("%d",&a);	
	  	enqueue(q,a);
	  }			
	 else if(ch=='d')	 dequeue(q);
	 else if(ch=='p') print(q);
	 else if(ch=='s') break;
	}
	
	return 0;
}
