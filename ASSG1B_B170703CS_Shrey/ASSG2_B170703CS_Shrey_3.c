#include<stdio.h>

int main(){


// Program to find largest odd integer
  

  int n;
  scanf("%d",&n);

  int a[n];
 
   for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
    
   int max=0;
   for(int i=0;i<n;i++)
   {
    if(a[i]%2!=0&&(a[i]>max))
    {
     max=a[i];
    }


   }
  

   printf("Largest odd integer is %d",max);



return 0;
}
