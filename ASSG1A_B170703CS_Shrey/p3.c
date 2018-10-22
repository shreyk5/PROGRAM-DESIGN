#include<stdio.h>

int check(int x){


int count=0;

for(int i=1;i<=x;i++)
if(x%i==0)
count++;

if(count==2)
return 1;

return 0;

}


int main(){
int a,b;

scanf("%d%d",&a,&b);

int c=0;

for(int i=a;i<=b;i++)
{
 if(check(i))
{ printf("%d ",i);
c++;}

}

if(c==0)
{  printf("No prime numbers between %d and %d",a,b);
}

return 0;
}
