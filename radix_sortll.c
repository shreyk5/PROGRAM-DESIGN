#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{	
	int data;
    struct node *next;	
};

struct list
{
	struct node *first_address;
	struct node *last_address;
        int number;	
};

struct node *head=NULL;
void add_node(int val)
{
  
  	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->next=NULL;
	 
	if(head==NULL)
	  head=new_node;
	  
	  else
	  {
	     struct node *curr=head;
             new_node->next=head;
	     head=new_node;
	  }   		
}


void radix_sort(int max_digits,int n)
{
    int exp=1;
    int digit;
    int output[n];
    struct node *curr;

    while(max_digits--)
    {
      curr=head;
      int count[10]={0};
    for (int i = 0; i < n; i++)
    {
       count[((curr->data)/exp)%10]++;
       curr=curr->next;
    }

    for (int i=1; i<10; i++)
           count[i] += count[i-1];

    curr=head;
    for (int i = n-1;i>=0;i--)
     {
              digit=((curr->data)/exp)%10 ;
              output[count[digit]-1] = (curr->data);
              count[digit]--;
              curr=curr->next;
     }
         
     exp=exp*10;
     free(head);
     head=NULL;

      for(int i=0;i<n;i++)
      {
         add_node(output[i]);
      }
	struct node *current=head;
     while(current!=NULL)
      {
        printf("%d ",current->data);
          current=current->next;
       }
	printf("\n");				
   }     
}

int main()
{  
   FILE *fp;
	fp=fopen("radin.txt","r");
	
	int a,n=0;
	int max=-1;
	
	   while(fscanf(fp,"%d",&a)!=EOF)
        {
          if(max<a)
           max=a;
		  add_node(a);  	
     	  n++;
	 }
     int digits=0;
     digits=floor(log10(max))+1;
     radix_sort(digits,n);
     struct node *current=head;
     while(current!=NULL)
      {
        printf("%d ",current->data);
          current=current->next;
       }	
   
  return 0;
}
