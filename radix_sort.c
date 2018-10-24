#include<stdio.h>
#include<math.h>

void radix_sort(int *a,int max_digits,int n)
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
     {
      a[i]=output[i];
       printf("%d ",a[i]);
     } 
       printf("\n");
   }
}

int main()
{
  int n=0;

  FILE *fp=fopen("radix.txt","r");  
  

  int a[100000];
  int digits=0;
  
    int i=0;
    while(fscanf(fp,"%d",&a[i])!=EOF)
   {  
     if((floor(log10(a[i]/1.0))+1)>digits)
       digits=floor(log10(a[i]/1.0))+1;
      i++;
      n++;
   }
  
  radix_sort(a,digits,i);

  //for(int i=0;i<n;i++)
   //printf("%d ",a[i]);

  return 0;
}
