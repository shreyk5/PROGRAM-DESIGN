#include<stdio.h>

int gcd(int a,int b)
{


if(a==0)
return b;

else
{

if(a<0)
a=-a;

if(b<0)
b=-b;

return gcd((a>b?a:b)-(a<b?a:b),(a<b?a:b));


}

}


int main()
{

int a,b;
scanf("%d%d",&a,&b);

int g;
g=gcd(a,b);

printf("The gcd of numbers is %d",g);

}
