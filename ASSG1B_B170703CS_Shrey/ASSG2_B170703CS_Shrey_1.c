#include<stdio.h>

int main()
{    
  int n;
  scanf("%d",&n);
  int a[n];
  
  for(int i=0;i<n;i++)
   {
    scanf("%d",&a[i]);
   }

  int f[100000];
  for(int i=0;i<100000;i++)
   f[i]=0; 
   
  for(int i=0;i<n;i++)
  {
   f[a[i]]++;
  
  }
  
  for(int i=0;i<100000;i++)
  {

   if(f[i]!=0)
   printf("Frequency of %d is %d\n",i,f[i]);
    
  }




return 0;
}
