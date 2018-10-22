#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);

int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);

// second largest 
// smallest
int t;

for(int i=0;i<n;i++)
for(int j=0;j<(n-i-1);j++)
  if(a[j]>a[j+1])
  {
   t=a[j]; 
   a[j]=a[j+1];   
   a[j+1]=t;
  }
int l;
int i=n-1;
l=a[n-2];

while(l==a[n-1])
{
 l=a[i-1];
  i--;
}


printf("Second largest element is %d\nSmallest element is %d ",l,a[0]);


return 0;
}
