#include<stdio.h>
#include<stdlib.h>
#define MAX 100001

int max_size;

struct node
{
   int data;
   struct node *next;

};

struct stack 
{
  	struct node *head;
	int size;	
	int top;
};

//struct node *head=NULL;
void insert_begin(struct stack *s,int val)
{
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=val;
    struct node *temp=s->head; 
     
	if(s->head==NULL)
	 {
	 	newNode->next=NULL;
	    s->head=newNode;
		s->size=1; 	 	
	 } 
   
    else
	{
		s->head=newNode;
		newNode->next=temp;
		s->size=s->size+1;
    }	

}


struct stack* new_stack()
{
   struct stack* s=(struct stack*)malloc(sizeof(struct stack));
   s->head=NULL;
   s->size=0;
   	s->top=-1;
   return s;
} 


void push(struct stack *s,int val)
{
	    insert_begin(s,val);
	 	s->top=val;	
}

void pop(struct stack *s)
{
	
	if(s->size==0) printf("EMPTY\n");
	else
	{
	  printf("%d ",(s->head)->data);
	  s->head=(s->head)->next;	
	  s->size=s->size-1;
	} 	
}

void print(struct stack *s)
{
	if(s->size==0) printf("EMPTY\n");
	
	else
	{
	 struct node *curr=s->head;
	 while(curr!=NULL)
	{
	  printf("%d ",curr->data);	
	  curr=curr->next;		
	}
    }
}

int main()
{
    int n;
    struct stack *s1=new_stack(); 
	while(1)
	{
		printf("Enter operation ");
		scanf("%d",&n);
		int a;
		if(n==1)
		{
			printf("Enter the element to be inserted ");
			scanf("%d",&a);
			push(s1,a);
		}
		if(n==2)
		pop(s1);
		
		if(n==3)
		 print(s1);
		 
		if(n==4) break; 
		
		
    }
   
	return 0;
}
