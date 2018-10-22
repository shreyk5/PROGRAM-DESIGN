#include<stdio.h>

int main()
{

float n;
printf("Enter a number");
scanf("%f",&n);

int x[4];

if(n<0||n>1)
printf("Entered number is not a positive decimal fraction less than 1");

else
{
printf("Binary eq is .");
   for(int i=0;i<4;i++)
  { 
    n=n*2;
    x[i]=(int)n;
    n=n-(int)n;
    printf("%d",x[i]);
  }
 
if((n)!=0)
printf("...");


}
return 0;
}
