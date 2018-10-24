#include<stdio.h>

void max_heapify(int *a,int n,int i)
{
	int largest=i;  //index of largest among i,2*i+1,2*i+2
	int left=2*i+1;
 	int right=2*i+2;
        int temp;
    
	if(left<n&&a[largest]<a[left]) largest=left;
	if(right<n&&a[largest]<a[right]) largest=right;
	
	if(largest!=i)
	{
	  temp=a[i];
	  a[i]=a[largest];
	  a[largest]=temp;	
	  max_heapify(a,n,largest);	
    
    }
}

void heap_sort(int *a,int n)
{
	int temp;
	int heap_size=n;
	int i;
	for(i=n/2-1;i>=0;i--)
		max_heapify(a,n,i);
    
    for(i=n-1;i>=0;i--)
    {
      temp=a[0];
      a[0]=a[i];	
      a[i]=temp;
      heap_size--;
      max_heapify(a,heap_size,0);
    }
		
}

int main(int argc,char *argv[])
{
	if(argc<3) printf("INSUFFICIENT ARGUMENTS\n");
	
	else
	{
	FILE *fp=fopen(argv[1],"r");
	FILE *ft=fopen(argv[2],"w");
	int n;
	fscanf(fp,"%d",&n);
	
	int a[n];
	int i;
	for(i=0;i<n;i++) fscanf(fp,"%d",&a[i]);
		
	heap_sort(a,n);
	for( i=0;i<n;i++) fprintf(ft,"%d ",a[i]);
   }
}
	
	
	

