#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;

};


struct node *head=NULL;

void add_node(int value)
{
   struct node *newNode=(struct node*)malloc(sizeof(struct node));

   if(head==NULL)
   {
      head=newNode;
      head->data=value;
      head->next=NULL;
   }

    else
   {
     struct node *currentNode;
     currentNode=head;

     while(currentNode->next!=NULL)
       currentNode=currentNode->next;

      currentNode->next=newNode;
      newNode->data=value;
      newNode->next=NULL;


   }


}


void find(int position)
{
   struct node *currentNode=head;

   for(int i=0;i<position;i++)
    currentNode=currentNode->next;

    printf("%d\n",currentNode->data);


}

int main()
{

   int n;
   printf("Enter the number of elements to be added in the list\n");
   scanf("%d",&n);

   printf("Enter the elements to be added in the list\n");
   int a[n];

   for(int i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
     add_node(a[i]);
   }
   int k;
   printf("Enter the value of k");
       scanf("%d",&k);

   find(n-k);
  
  return 0;
}



