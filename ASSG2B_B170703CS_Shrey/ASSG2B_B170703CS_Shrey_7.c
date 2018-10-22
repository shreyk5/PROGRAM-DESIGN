#include<stdio.h>

struct employee
{
  char name[20];
  int salary;
  int wpd;

};

struct employee e[10];
int count=0;
int flag=0;
int inc=0;

void function(int option)
{

   if(option==1)
   {
      printf("Name ");
      scanf("%s",e[count].name);

      printf("Salary ");
      scanf("%d",&e[count].salary);

      printf("Work per day ");
      scanf("%d",&e[count].wpd);

       count++;

   }

   if(option==2)
   {

       
   if(!inc)
   {
   for(int i=0;i<count;i++)
      {

         if(e[i].wpd==8)
         	 e[i].salary=e[i].salary+50;

          else if(e[i].wpd==10)
             e[i].salary=e[i].salary+100;

         else if(e[i].wpd>=12)
             e[i].salary=e[i].salary+150;

      }
      inc=1;

    }


   	   printf("Employees whose salary did not get incremented\n");

      for(int i=0;i<count;i++)
      {
         if((e[i].wpd!=8)&&(e[i].wpd!=10)&&(e[i].wpd<12))
         {
            printf("Name %s\n",e[i].name);
            printf("Final salary %d\n",e[i].salary);
            flag=1;
         }
      }

       if(flag==0)
       	printf("Salaries of all Employees got incremented\n");

   }


   if(option==3)

     {

       
   if(!inc)
   {
   for(int i=0;i<count;i++)
      {

         if(e[i].wpd==8)
         	 e[i].salary=e[i].salary+50;

          else if(e[i].wpd==10)
             e[i].salary=e[i].salary+100;

         else if(e[i].wpd>=12)
             e[i].salary=e[i].salary+150;

      }
      inc=1;

    }



      for(int i=0;i<count;i++)
      {

            printf("Name %s\n",e[i].name);
            printf("Final salary %d\n",e[i].salary);


      }


    }

  if(option==4)
   {
      int w;
      printf("Enter the work per day ");
      scanf("%d",&w);
      int f=0;


      for(int i=0;i<count;i++)
      {
            if(w==e[i].wpd)
            {
            printf("Name %s\n",e[i].name);
            printf("Final salary %d\n",e[i].salary);
            f=1;
           }

      }

      if(f==0)
       printf("Employee not found\n");


   }

  if(option==5)
  	 return;

}


int main()
{

  int n;
  while(1)
  {

     printf("Enter your choice ");
     scanf("%d",&n);
     function(n);


     if(n==5)
     	break;

  }


	return 0;
}
