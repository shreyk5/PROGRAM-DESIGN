#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;

};

void max_heapify(struct node **arr,int n,int i)
{
	int largest=i;  //index of largest among i,2*i+1,2*i+2
	int left=2*i+1;
 	int right=2*i+2;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    
	if(left<n&&(arr[largest]->data)<(arr[left]->data)) largest=left;
	if(right<n&&(arr[largest]->data)<(arr[right]->data)) largest=right;
	
	if(largest!=i)
	{
	  temp=arr[i];
	  arr[i]=arr[largest];
	  arr[largest]=temp;	
	  max_heapify(arr,n,largest);	
    }
}

void heap_sort(struct node **arr,int n)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	int heap_size=n;
	int i;
	for(i=n/2-1;i>=0;i--)
		max_heapify(arr,n,i);
    
    for(i=n-1;i>=0;i--)
    {
      temp=arr[0];
      arr[0]=arr[i];	
      arr[i]=temp;
      heap_size--;
      max_heapify(arr,heap_size,0);
    }
		
}


int main(int argc,char *argv[])
{
	int n=0;
	int i,a;
    if(argc<3) printf("INSUFFICIENT ARGUMENTS\n");
	
	else
	{
	FILE *fp=fopen(argv[1],"r");
	FILE *ft=fopen(argv[2],"w");

	while(fscanf(fp,"%d",&a)!=EOF)
	 n++;

	struct node *arr[n];
	for(i=0;i<n;i++)
    arr[i]=(struct node*)malloc(sizeof(struct node));
    
	fp=fopen(argv[1],"r");
	i=0;
	while(fscanf(fp,"%d",&(arr[i]->data))!=EOF)
      i++;

	 heap_sort(arr,n);
	 struct node *head=arr[0];

	 for(i=0;i<n-1;i++)
	 arr[i]->next=arr[i+1];

	 arr[n-1]->next=NULL;
	 
	 struct node *curr=head;
	 while(curr)
	 {
       fprintf(ft,"%d ",curr->data);
	   curr=curr->next;
	 }
	
   }
}