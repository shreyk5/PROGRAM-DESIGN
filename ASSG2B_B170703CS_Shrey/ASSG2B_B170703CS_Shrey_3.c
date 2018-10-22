#include<stdio.h>
#include<stdlib.h>

struct customer
{
   char name[30];
   int ac_num;
   int balance;

};

int count=0;
int flag=1;


struct customer p[10];

void function(int option)
{


    struct customer p[10];

   if(option==1)
   {


              printf("Name ");
              fgetc(stdin);
              fgets(p[count].name,20,stdin);
              printf("Account number ");
              scanf("%d",&(p[count].ac_num));
                if(p[count].ac_num<100000)
                 {
                   printf("Invalid account number ,Enter more than 100000 ");
                    scanf("%d",&(p[count].ac_num));
                 }

              printf("Balance ");
              scanf("%d",&((p[count].balance)));
               if(p[count].balance<10)
                 {
                   printf("Invalid balance ,Enter more than 10 ");
                    scanf("%d",&(p[count].balance));
                 }

              printf("\n");

          count++;

   }

       if(option!=1&&flag)
       {
         for(int i=0;i<count;i++)
          {
              if((p[i].balance)>1000)
               p[i].balance=p[i].balance+100;
          }
         flag=0;
       }

       if(option==2)   // Display the name of customers having balance less than 200.
       {
           int a=0;

          printf("Customers having balance less than 200\n");
          for(int i=0;i<count;i++)
          {
             if((p[i]).balance<200)
             {
                 a++;
                 printf("Name ");
                 printf("%s",(p[i]).name);
             }

          }

          if(a==0)
          printf("No customer has balance less than 200\n");

                    printf("\n");
       }

       if(option==3)  //Display the details of the customers whose balance amount got incremented
       {
         int b=0;

         printf("Customers whose balance amount got incremented\n");
          for(int i=0;i<count;i++)
          {
             if(p[i].balance>1100)
             {
                 b++;
                 printf("Name ");
                 printf("%s",(p[i]).name);
                 printf("\n");
                 printf("Account number ");
                 printf("%d",(p[i].ac_num));
                 printf("\n");
                 printf("Balance ");
                 printf("%d",(p[i].balance));
                 printf("\n");

             }

          }
          printf("\n");
           if(b==0)
             printf("None of the customers' balance got incremented\n");

       }



              if(option==4)   //display all customers
              {
                 for(int i=0;i<count;i++)
                 {

                   printf("Name ");
                   printf("%s",(p[i]).name);
                   
                   printf("Account number ");
                   printf("%d",(p[i].ac_num));
                   printf("\n");
                   printf("Balance ");
                   printf("%d",(p[i].balance));
                   printf("\n");

                 }

              }

              if(option==5)
              return;



}


int main()
{
  /*1.Add a customer record
  2.Display the name of customers having balance less than 200.
  3.Display the details of the customers whose balance amount got incremented.
  4.Display the details of all the customers.
  5.Exit  */
int n;

while(1)
  {
    printf("Enter your choice ");
    scanf("%d",&n);
    if(n!=5)
    function(n);

    else
    break;

  }
  return 0;

}

