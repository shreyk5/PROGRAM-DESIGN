#include<stdio.h>
#include<math.h>

int main()
{

float a,b,c;
printf("Enter a ,b and c");
scanf("%f%f%f",&a,&b,&c);

float x1,x2;

  if(a==0&&b!=0)
  {
   printf("Linear Equation\n"); 
   x1=-c/b;
   printf("Root is %.3f\n",x1);
  }

   else if(a==0&&b==0)
  {
   if(c==0)
   printf("Infinite solutions");
   else
   printf("No solutions");
  }
  else
 {
  float d=(b*b)-(4*a*c);
   if(d>=0)
   {
     printf("Roots are real \n");
     printf("Roots\n");
     x1=(-b+sqrt(d))/(2*a);
     x2=(-b-sqrt(d))/(2*a);
     printf("%.3f and %.3f\n",x1,x2);
   }
 
   else
  {
     float x3,x4;
     printf("Roots are imaginary\n");
     x1=-b/(2*a);
     x3=(sqrt(-d))/(2*a);
     x2=-b/(2*a);
     x4=(-sqrt(-d))/(2*a);
     printf("Roots are\n");
     if(a>0)
     printf("%.3f+%.3fi and %.3f %.3fi ",x1,x3,x2,x4);
     if(a<0)
     printf("%.3f %.3fi and %.3f+%.3fi ",x1,x3,x2,x4);
  }



}
return 0;
}
