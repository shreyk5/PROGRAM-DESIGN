#include<stdio.h>
int main(){


int n;
scanf("%d",&n);

int a=n;
int sum=0;

while(a)
{
sum=sum+((a%10)*(a%10)*(a%10));
a=a/10;
}

if(sum==n)
printf("%d is an Amstrong number",n);

else
printf("%d is not an Amstrong number",n);



return 0;
}
