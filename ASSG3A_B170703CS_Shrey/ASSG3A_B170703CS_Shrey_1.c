#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *inputFile;
    inputFile=fopen("1.txt","r");

  char c;
  int n;
while (fscanf(inputFile,"%d",&n)!=EOF)
{

  int a[n];

  for(int i=0;i<n;i++)
   fscanf(inputFile,"%d",&a[i]);

   int find;
   fscanf(inputFile,"%d",&find);


   printf("Number of elements are %d \n",n);

   printf("elements of the array are ");

   for(int i=0;i<n;i++)
      printf("%d ",a[i]);

   printf("The element to be found is %d \n",find);

   int s=0,e=n-1;
   int mid;
   int flag=0;

   while(s<=e)
   {
     mid=(s+e)/2;

      if(a[mid]==find)
       {
         printf("Element found at %d\n",mid);
         flag=1;
         break;
       }

       else if(a[mid]<find)
       {
         s=mid+1;

       }
       else
       e=mid-1;
   }
   if(flag==0)
    printf("Element not found\n");

}

  return 0;
}
