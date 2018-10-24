#include<stdio.h>
#include<stdlib.h>
#define MAX 100001

struct stack
{
  int a[MAX];
  int size;
  int top;		
};
int max_size;

struct stack* new_stack()
{
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=0;
    
    return s;
}

void push(struct stack *s,int data)
{
	if(s->size==(max_size)) printf("OVERFLOW\n");
	else
	{
	s->a[s->size]=data;
	s->size=(s->size)+1;
	s->top=data;
	}	
}

void pop(struct stack *s)
{
	
	 if(s->size==0) printf("EMPTY\n");
	else {
		
		if(s->size==1)
		{
		  printf("%d ",s->top);
		  s->size=0;
		  s->a[(s->size)]=0;
		}
		
		else
		{
		printf("%d ",s->top);
		s->a[(s->size)-1]=0;
		s->size=(s->size)-1;
		s->top=s->a[(s->size)-1];
	    }
}
	
}

void print(struct stack *s)
{
	if((s->size)==0)  printf("EMPTY\n");
	else
	{
		int i;
		for(i=(s->size)-1;i>=0;i--)
		{
			printf("%d ",(s->a[i]));
		}
	}
	
}

int main()
{
	int n;
	//int size;
	printf("Enter the size of stack ");
	scanf("%d",&max_size);
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
	
}

