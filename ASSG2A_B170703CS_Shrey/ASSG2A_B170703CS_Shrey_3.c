#include<stdio.h>
#include<stdlib.h>

int flag=1;
struct matrix
{
int r;
int c;
int *a;
};
struct matrix m1;
struct matrix m2;
struct matrix m3;
struct matrix m4;

void read()
{

scanf("%d",&m1.r);
scanf("%d",&m1.c);
m1.a=(int *)malloc((m1.r)*(m1.c)*sizeof(int));

for(int i=0;i<m1.r;i++)
  for(int j=0;j<m1.c;j++)
      {scanf("%d",(m1.a+i*(m1.c)+j)); }
}
/*
scanf("%d",&m2.r);
scanf("%d",&m2.c);

for(int i=0;i<m2.r;i++)
  for(int j=0;j<m2.c;j++)
      scanf("%d",&m2.a[i][j]);

}

void print()
{

printf("Matrix A is \n");
for(int i=0;i<m1.r;i++)
{
  {
   for(int j=0;j<m1.c;j++)
   printf("%d ",m1.a[i][j]);
  }
 printf("\n");
}

printf("Matrix B is \n");

for(int i=0;i<m2.r;i++)
{
  {
   for(int j=0;j<m2.c;j++)
   printf("%d ",m2.a[i][j]);
  }
 printf("\n");
}

}
struct matrix add()
{
        if(m1.c==m2.c&&m1.r==m2.r)
	{
         for(int i=0;i<m1.r;i++)
         {
  		
   		for(int j=0;j<m1.c;j++)
                m3.a[i][j]=m1.a[i][j]+m2.a[i][j];
                
	 }
      } 
    else { flag=0; printf("not possible");}
return m3;  
    
}
struct matrix sub()
{
        if(m1.c==m2.c&&m1.r==m2.r)
	{
         for(int i=0;i<m1.r;i++)
         {
  		
   		for(int j=0;j<m1.c;j++)
                m4.a[i][j]=m1.a[i][j]-m2.a[i][j];
                
	 }
      } 
    else { flag=0; printf("not possible");}
return m4;  
    
}
*/
int main()
{
read();
for(int i=0;i<m1.r;i++)
{
  {
   for(int j=0;j<m1.c;j++)
   {printf("%d ",*(m1.a+i*(m1.c)+j));
     }
  }
 printf("\n");
}



return 0;
}
