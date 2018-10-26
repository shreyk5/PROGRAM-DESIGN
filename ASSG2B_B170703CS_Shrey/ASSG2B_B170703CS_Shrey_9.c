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

void found(int val)
{

  struct node *currentNode=head;
  int i=0;   //position
  int flag=0;

  while(currentNode!=NULL)
  {
     if(currentNode->data==val)
      {
        flag=1;
        break;
      }
    currentNode=currentNode->next;
    i++;
  }

  if(flag)
  printf("Element found at %d\n",i+1);

  else
  printf("Element not found");

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

  int val;
  printf("Enter element to be searched");
  scanf("%d",&val);
  found(val);

  return 0;
}
