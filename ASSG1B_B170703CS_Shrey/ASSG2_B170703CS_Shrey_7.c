#include<stdio.h>

int main()
{
 
int m,n;
printf("enter the value of m");
scanf("%d",&m);

printf("enter the value of n");
scanf("%d",&n);
int a[m][n];

 for(int i=0;i<m;i++)
 {
   for(int j=0;j<n;j++)
   scanf("%d",&a[i][j]);
 }

for(int i=0;i<n;i++)
 {
   for(int j=0;j<m;j++)
   printf("%d ",a[j][i]);
   
   printf("\n");
   
 }


return 0;
}
