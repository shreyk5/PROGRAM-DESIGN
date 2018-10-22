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

void delete_node(int position)
{
    struct node *currentNode=head;

    for(int i=0;i<position-1;i++)
     currentNode=currentNode->next;

     currentNode->next=(currentNode->next)->next;

}

void delete_duplicate()
{
    struct node *currentNode=head;
    int i=0;

    while(currentNode->next!=NULL)
    {
         if(currentNode->data==(currentNode->next)->data)
           {
            delete_node(i+1);
            i--;
           }
            else{
         currentNode=currentNode->next;
            }

        i++;
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
     delete_duplicate();
      printf("Elements in the list are ");
   print();

return 0;
}
