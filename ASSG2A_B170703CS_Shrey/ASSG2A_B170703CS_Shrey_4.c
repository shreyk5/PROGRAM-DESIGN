#include<stdio.h>

long long add(int n,int x,int y)
{
long long sum=0;

 for(int i=1;i<n;i++)
 {
	if(i%x==0||i%y==0)
         sum=sum+i;
 }

return sum;

}

int main()
{

int n,x,y;
printf("enter n,x,y");
scanf("%d%d%d",&n,&x,&y);

long long res=add(n,x,y);
printf("Total sum is %lld",res);


return 0;
}
