#include<stdio.h>

int main()
{

int n;
scanf("%d",&n);

int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

int x,y;
printf("Enter element to be replaced ");

scanf("%d",&x);

printf("Enter element to be inserted ");
scanf("%d",&y);

int count=0;

  for(int i=0;i<n;i++)
  {
   if(a[i]==x)
    {
      a[i]=y;
      count++;
    }   
  }
  
  if(count==0)
  printf("%d is NOT Found in the array",x);

  else
  {
   printf("Resultant array is ");
   for(int i=0;i<n;i++)
   printf("%d ",a[i]);

  }



return 0;
}
