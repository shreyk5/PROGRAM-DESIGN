#include<stdio.h>
int main()
{

int n1,n2;
scanf("%d",&n1);

int f[100000];

   for(int i=0;i<100000;i++)
   f[i]=0;

int a[n1+100000];
  for(int i=0;i<n1;i++)
  {
  scanf("%d",&a[i]);
  f[a[i]]++;
  }

scanf("%d",&n2);
int b[n2];

for(int i=0;i<n2;i++)
{
scanf("%d",&b[i]);
f[b[i]]++;
}

int c;
int d=0;


printf("Merged array is ");
 
    for(int i=0;i<n1;i++)
    { 
      if(f[a[i]]>0)  
     printf("%d ",a[i]);

      f[a[i]]=-1;
     }
    for(int i=0;i<n2;i++)
    {
     if(f[b[i]]>0)
     printf("%d ",b[i]);
     
      f[b[i]]=-1;

    }

return 0;
}

