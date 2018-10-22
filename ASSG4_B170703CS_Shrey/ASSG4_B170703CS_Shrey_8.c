#include<stdio.h>
#include<stdlib.h>

int main()
{
   FILE *fp=fopen("8.txt","r");
   int n,m;

   fscanf(fp,"%d",&n);
   fscanf(fp,"%d",&m);
   int a[n],b[m];
    
   for(int i=0;i<n;i++) 
    fscanf(fp,"%d",&a[i]);
   for(int i=0;i<m;i++) 
    fscanf(fp,"%d",&b[i]);

   int i=0,j=0,k=0;

   int c[n+m];

   for(int k=0;k<n+m;k++)
   {
      if(i==n)
       {
              c[k]=b[j];
           j++;
       }
      else if(j==m)
      {
         c[k]=a[i];
         i++; 
      }
     
     else if(a[i]>=b[j])
      {
          c[k]=b[j];
           j++;
      }
      else
      {
         c[k]=a[i];
         i++;
      }
   }

   for(int i=0;i<n+m;i++)
    printf("%d ",c[i]);


}