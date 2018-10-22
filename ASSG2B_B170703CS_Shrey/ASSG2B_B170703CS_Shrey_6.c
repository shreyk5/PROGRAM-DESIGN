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


void reverse()
{
   struct node *temp=head;           //just keeps the head safe
   struct node *currentNode=head;
   struct node *previousNode=NULL;
   struct node *nextNode;

   while(currentNode->next!=NULL)
   {
      currentNode=currentNode->next;
   }



   head=currentNode;
   currentNode=temp;

   while(currentNode!=NULL)
   {
      nextNode=currentNode->next;
      currentNode->next=previousNode;

      //previousNode=previousNode->next;
      previousNode=currentNode;
      currentNode=nextNode;
   }

   temp->next=NULL;

    printf("Reversed list is ");


}


void print()
{

   struct node *currentNode=head;

   while(currentNode!=NULL)
   {
       printf("%d ",currentNode->data);
       currentNode=currentNode->next;
   }

     printf("\n");
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
  
  reverse();
  print();

  return 0;
}

