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
      // printf("%d ",a[i]);
     } 
      // printf("\n");
   }
}


int main()
{
  FILE *fp=fopen("sortin.txt","r");
   
  int n1,n2;
  n1=0,n2=0;
  char ch;
  while(1)
  {
      fscanf(fp,"%c",&ch);
      if(ch=='\n') break;
      if(ch==' ')  
      n1++;
  }
  while(fscanf(fp,"%c",&ch)!=EOF)
  {
      
      if(ch==' ')  
      n2++;
  }
   n1++;
   n2++;

 //  printf("%d %d\n",n1,n2);
   int a[n1],b[n2];
   fclose(fp);
   fp=fopen("sortin.txt","r");

   for(int i=0;i<n1;i++)
     fscanf(fp,"%d",&a[i]);
 
   for(int i=0;i<n2;i++)
     fscanf(fp,"%d",&b[i]);

   int max=0,max2=0;
   
  for(int i=0;i<n1;i++)
   if(a[i]>max) max=a[i];
   
  for(int i=0;i<n2;i++)
   if(b[i]>max2) max2=b[i];

  //printf("%d %d\n",max,max2);

   int f1[max+1];
   int f2[max2+1];
   for(int i=0;i<max+1;i++)
    f1[i]=0;

    for(int i=0;i<max2+1;i++)
    f2[i]=0;

     for(int i=0;i<n1;i++)
      f1[a[i]]++;

      for(int i=0;i<n2;i++)
        f2[b[i]]++;

    int c[n1];

    int j=0;
    for(int i=0;i<n2;i++)
    {
      //  printf("%d ",b[i]);
        if(f1[b[i]]>0)
          while(f1[b[i]]--)
           {
               c[j]=b[i];
                j++;
           }    
    }

    int d[n1-j];
    int k=0;
    int max1=0;

    for(int i=0;i<n1;i++)
     {
        if(f2[a[i]]==0)
         {
           d[k]=a[i];
           if(max1<a[i]) max1=a[i];

           k++;
         }

     }

    radix_sort(d,floor(log10(max1))+10,n1-j); 
   for(int i=j;i<n1;i++)
    c[i]=d[i-j];

     for(int i=0;i<n1;i++)
    printf("%d ",c[i]);
    

}