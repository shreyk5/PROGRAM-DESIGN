#include<stdio.h>
// n fibonacci numbers

int main(){

int n;
scanf("%d",&n);

int f[n];

f[0]=0;
f[1]=1;

printf("%d %d ",f[0],f[1]);

for(int i=2;i<n;i++)
{

f[i]=f[i-1]+f[i-2];
printf("%d ",f[i]);

}










return 0;
}
