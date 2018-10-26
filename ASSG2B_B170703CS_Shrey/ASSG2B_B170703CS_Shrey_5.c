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

void swap()
{
    struct node *currentNode=head->next;
    struct node *previousNode=head;

    while(previousNode!=NULL&&currentNode!=NULL)
    {

        int temp=currentNode->data;
        currentNode->data=previousNode->data;
        previousNode->data=temp;

        previousNode=currentNode->next;

        if(currentNode->next!=NULL)
        currentNode=previousNode->next;
    }

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

  swap();
  printf("Elements of the list after pairwise swapping ");
  print();

  return 0;
}
