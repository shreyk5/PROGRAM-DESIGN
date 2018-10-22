#include<stdio.h>

int Sorted_asc(int *a,int n)
{
  int count=0;

  for(int i=0;i<n-1;i++)
   if(a[i+1]>=a[i]) count++;

  if(count==n-1)
   return 1;

   return 0;

}
int Sorted_des(int *a,int n)
{
  int count=0;

  for(int i=0;i<n-1;i++)
   if(a[i+1]<=a[i]) count++;

  if(count==n-1)
   return 1;
   
   return 0;

}

void bubble_sort(int *a,int n)
{
    int t;
   for(int i=0;i<n;i++)
    for(int j=0;j<n-i-1;j++)
     if(a[j]>a[j+1])
      {
        t=a[j];
         a[j]=a[j+1];
         a[j+1]=t;
      }

}

int main()
{
  FILE *fp=fopen("10.txt","r");

  int n,m;
  fscanf(fp,"%d",&n);
  
  int a[n];

  for(int i=0;i<n;i++)
   fscanf(fp,"%d",&a[i]);

   if(Sorted_asc(a,n)==0&&Sorted_des(a,n)==0)
   {
        printf("The array is not sorted\n");
           bubble_sort(a,n);
   }
   
   else if(Sorted_asc(a,n)==1)
        printf("The array is sorted in ascending order\n");
    
    else if(Sorted_des(a,n)==1)
        printf("The array is sorted in descending order\n");

   for(int i=0;i<n;i++)
    printf("%d ",a[i]);

    printf("\n");
   return 0;
}