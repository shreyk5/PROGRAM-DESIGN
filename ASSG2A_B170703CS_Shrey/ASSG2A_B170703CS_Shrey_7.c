#include<stdio.h>

long long sum(int *a,int n)
{
long long ans=0;

for(int i=0;i<n;i++)
{
if((a[i]>999&&a[i]<10000&&a[i]%2==0)||(a[i]<(-999)&&a[i]>(-10000)&&a[i]%2==0))
ans=ans+a[i];
}

return ans;

}

int main()
{
printf("Enter number of elements");
int n;
scanf("%d",&n);

int a[n];

for(int i=0;i<n;i++)
scanf("%d",&a[i]);
long long res;

res=sum(a,n);

printf("The sum is %lld",res);
return 0;
}
