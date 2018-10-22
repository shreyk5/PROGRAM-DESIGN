#include<stdio.h>

int main(){
    
   int n;
   scanf("%d",&n);
    
   int a[n];
   for(int i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
     
   int k;         // delete element at kth position
   scanf("%d",&k);
    
   if(k>n)
   printf("INVALID INDEX"); 
   
   else
  {

   for(int i=k-1;i<n-1;i++)
   {
    a[i]=a[i+1];  
   }
   printf("Resultant array is ");
   for(int i=0;i<n-1;i++)
   printf("%d ",a[i]);
 }




return 0;
}




 
