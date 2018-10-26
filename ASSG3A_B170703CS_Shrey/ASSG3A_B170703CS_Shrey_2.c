#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *inputFile;
    inputFile=fopen("2.txt","r");


  int k;
while (fscanf(inputFile,"%d",&k)!=EOF)
{
   printf("Element to be searched is %d\n",k);
  int n;
  fscanf(inputFile,"%d",&n);
  int a[n];

  for(int i=0;i<n;i++)
   fscanf(inputFile,"%d",&a[i]);


   printf("Number of elements are %d \n",n);

   printf("elements of the array are ");

   for(int i=0;i<n;i++)
      printf("%d ",a[i]);

    int flag=0;

      for(int i=0;i<n;i++)
         {
           if(a[i]==k)
            {
                printf("Element fount at %d \n",i);
                flag=1;
            }
        }
     if(flag==0)
      printf("Element not found\n");

      printf("\n");
}
return 0;
}
