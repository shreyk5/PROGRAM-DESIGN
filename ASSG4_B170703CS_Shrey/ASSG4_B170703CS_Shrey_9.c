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
    int k=0;
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
     printf("List after %d iteration ",k);
      print();
      k++;
}

}

int main()
{
   FILE *fp=fopen("9.txt","r");

   int a;
   while(fscanf(fp,"%d",&a)!=EOF)
    add_node(a);
   
    selection_sort();
    

}


