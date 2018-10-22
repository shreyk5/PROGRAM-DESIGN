#include <stdio.h>

long factorial(int n)
{
   
   long result = 1;
 
   for (int i= 1; i<= n; i++)
         result = result*i;
 
   return result;
}

 
int main()
{
   int i, n, c;
   scanf("%d",&n);
 
   for (i = 0; i < n; i++)  // for n rows
   {
      for (c = 0; c <= (n - i - 2); c++)
         printf(" ");
 
      for (c = 0 ; c <= i; c++)  // for i+1 elements in each row

          printf("%ld ",factorial(i)/(factorial(c)*factorial(i-c))); 
 
      printf("\n");
   }
 
   return 0;
}
 



