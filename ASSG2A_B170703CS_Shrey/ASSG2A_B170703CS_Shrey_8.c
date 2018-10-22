#include<stdio.h>

int check(int n)
 {

  int sum=0;
  for(int i=1;i<n;i++)
    if(n%i==0)
      sum=sum+i;
  if(sum==n)
   return 1;
 
  else
   return 0;
 }

int main()
{

int n;
printf("Enter an integer number");
scanf("%d",&n);

if(check(n))
printf("%d is a perfect number",n);

else
printf("%d is not a perfect number",n);

return 0;
}
