#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void radix_sort(int *a,int max_digits,int n,int asc)
{
    int exp=1;
    int digit;
    int output[n];
    while(max_digits--)
    {
      int count[10]={0};
    for (int i = 0; i < n; i++)
       count[(a[i]/exp)%10]++;

    for (int i=1; i<10; i++)
           count[i] += count[i-1];

    for (int i = n-1; i >= 0;i--)
     {
              digit=(a[i]/exp)%10 ;
              output[count[digit]-1] = a[i];
              count[digit]--;
     }
     exp=exp*10;

     
     for(int i=0;i<n;i++)
      a[i]=output[i];
    
   }
   
   if(asc==0)
    for(int i=0;i<n;i++)
     a[i]=output[n-i-1];


}



int main()
{
    FILE *fp=fopen("radin.txt","r");
    
    int n=0;
    int a[100000];
    int i=0;
    while(fscanf(fp,"%d",&a[i])!=EOF)
     {
         i++;
         n++;
     }

     int k=a[n-1];
     n--;
     // first k elements in ascending order and n-k elements in descending order
     int digits;
      for(int i=0;i<k;i++)
    {
       if((floor(log10(a[i]/1.0))+1)>digits)
         digits=floor(log10(a[i]/1.0))+1;
    }
    
    int b[k],c[n-k];
      for(int i=0;i<k;i++)
        b[i]=a[i];

      for(int i=k;i<n;i++)
        c[i-k]=a[i];

    radix_sort(b,digits,k,1);     
      for(int i=k;i<n;i++)
    {
       if((floor(log10(a[i]/1.0))+1)>digits)
         digits=floor(log10(a[i]/1.0))+1;
    }

    
    radix_sort(c,digits,n-k,0);
     
      for(int i=0;i<k;i++)
        a[i]=b[i];
      for(int i=k;i<n;i++)
        a[i]=c[i-k];

     for(int i=0;i<n;i++)
      printf("%d ",a[i]);

    return 0;
}