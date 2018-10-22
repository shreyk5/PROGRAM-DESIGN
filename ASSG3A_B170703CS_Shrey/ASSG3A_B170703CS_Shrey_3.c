#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *inputFile;
    inputFile=fopen("3.txt","r");


  int n;
while (fscanf(inputFile,"%d",&n)!=EOF)
{
  int a[n];

  for(int i=0;i<n;i++)
   fscanf(inputFile,"%d",&a[i]);

   printf("Number of elements are %d \n",n);

   int temp;

   for(int i=0;i<n;i++)
    for(int j=0;j<n-i-1;j++)
     {
       if(a[j]>a[j+1])
        {
          temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
        }

     }


        printf("Sorted elements of the array are ");
        for(int i=0;i<n;i++)
           printf("%d ",a[i]);

}

return 0;

}
