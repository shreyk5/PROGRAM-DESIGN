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
   int j;
    for(int i=1;i<n;i++)
    {
       temp=a[i];
       j=i-1;

       while(j>=0&&temp<a[j])
       {
          a[j+1]=a[j];
          j--;
       }

      a[j+1]=temp;

    }


        printf("Sorted elements of the array are ");
        for(int i=0;i<n;i++)
           printf("%d ",a[i]);

}

return 0;

}
