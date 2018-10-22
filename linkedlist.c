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

void find(int position)
{
   struct node *currentNode=head;

   for(int i=0;i<position;i++)
    currentNode=currentNode->next;

    printf("%d\n",currentNode->data);


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

void swap_node(struct node* prev_a,struct node* a,struct node* prev_b,struct node* b)
{
   struct node* temp1=a->next;
   struct node* temp2=b->next;

  if(a==b)
   return;
 
  else if(prev_b==a&&head!=a)
  {
    prev_a->next=b;
    b->next=a;
    a->next=temp2;
  }
   
   else if(prev_b==a&&head==a)
  {
    head=b;
    a->next=temp2;
    b->next=a;
  }
  

  else if(prev_a==b&&head!=b)
  {
    prev_b->next=a;
    a->next=b;
    b->next=temp1;
  }
   
   else if(prev_a==b&&head==b)
  {
    head=a;
    b->next=temp1;
    a->next=b;
  }


  
  else if(a==head)
  {
   head=prev_b->next;
   prev_b->next=a;
   b->next=temp1;
   a->next=temp2;
  }
 
    else if(b==head)
  {
   head=prev_a->next;
   prev_a->next=b;
   a->next=temp2;
   b->next=temp1;
  }

  else
  {
   prev_a->next=b;
   prev_b->next=a;
   b->next=temp1;
   a->next=temp2;
  }
}

void selection_sort()
{
   struct node* a=head;
   struct node* prev_a=NULL;
   struct node* previous;
   struct node* current;
   struct node* min_node;
    struct node* prev_min;
    int min;
while(a)
{
   min=1000000;
   previous=prev_a;
   current=a;
   min_node=a;
   prev_min=prev_a;

   while(current)
   {

         if(current->data<min)
         {
          min=current->data;
          prev_min=previous;
          min_node=current;
         }

          previous=current;
          current=current->next;
   }
     swap_node(prev_a,a,prev_min,min_node);
     prev_a=min_node;
     a=min_node->next;
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
 
  
  //swap_node(head,head->next,0,head);
  //selection_sort();
  print();

  return 0;
}
