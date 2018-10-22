#include<stdio.h>

int main(){

int n;
scanf("%d",&n);

int a[n];

for(int i=0;i<n;i++)
scanf("%d",&a[i]);

int k;
printf("Enter the position of the element to split the array");
scanf("%d",&k);
int t;

   if(k>n)
   printf("INVALID INDEX");

   else
  {
     for(int i=0;i<k-1;i++)
    {
       for(int j=0;j<n-1;j++)
       {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;  
   
       }

    }

   printf("The resultant array is ");
   for(int i=0;i<n;i++)
   printf("%d ",a[i]);
 }

return 0;
}
