#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}



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

   int min_index;

   for(int i=0;i<n-1;i++)
   {
     min_index=i;
    for(int j=i+1;j<n;j++)
     {
        if(a[min_index]>a[j])
         {

            min_index=j;

         }

     }
       swap(&a[min_index],&a[i]);
    }


        printf("Sorted elements of the array are ");
        for(int i=0;i<n;i++)
           printf("%d ",a[i]);

}

return 0;

}
