#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;

};


struct node *head1=NULL;
struct node *head2=NULL;

struct node* add_node(struct node *head,int value)
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

   return head;

}

   struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);

  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }

  return(result);

}




void print()
{

   struct node *currentNode=head1;

   while(currentNode!=NULL)
   {
       printf("%d ",currentNode->data);
       currentNode=currentNode->next;
   }
     printf("\n");
}





int main()
{
   int m,n;
   printf("Enter the value of m ");
   scanf("%d",&m);

   printf("Enter the value of n ");
   scanf("%d",&n);

   int a;

   printf("Enter the elements of linked list A ");
   for(int i=0;i<m;i++)
   {
      scanf("%d",&a);
      head1=add_node(head1,a);

   }

   printf("Enter the elements of linked list B ");

   for(int i=0;i<n;i++)
   {
      scanf("%d",&a);
      head2=add_node(head2,a);

   }
  head1=SortedMerge(head1,head2);
  print();







  return 0;
}
