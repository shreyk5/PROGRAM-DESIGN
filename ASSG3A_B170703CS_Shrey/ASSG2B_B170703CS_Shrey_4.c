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


void count_occurences()
{
    struct node *currentNode=head;

    int f[100000];
    for(int i=0;i<100000;i++)
      f[i]=0;

    while(currentNode!=NULL)
    {
        f[currentNode->data]++;
        currentNode=currentNode->next;
    }


    for(int i=0;i<100000;i++)
    {
      if(f[i])
      {
         printf("The number of occurences of %d is %d\n",i,f[i]);

      }

    }


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

   count_occurences();
  

  return 0;
}

