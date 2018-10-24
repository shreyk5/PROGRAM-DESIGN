#include<stdio.h>

int Sorted_asc(int *a,int n)
{
  int count=0;

  for(int i=0;i<n-1;i++)
   if(a[i+1]>=a[i]) count++;

  if(count==n-1)
   return 1;

   return 0;

}
int Sorted_des(int *a,int n)
{
  int count=0;

  for(int i=0;i<n-1;i++)
   if(a[i+1]<=a[i]) count++;

  if(count==n-1)
   return 1;
   
   return 0;

}


int partition (int arr[],int low,int high) 
{ 
    int pivot = arr[high];     
    int i = (low - 1);   
    int temp;
    int j;
    for (j = low; j <= high- 1; j++) 
    { 
     
        if (arr[j] <= pivot) 
        { 
            i++;    
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp; 
        } 
    } 
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low<high) 
    { 
        int p= partition(arr, low, high); 
  
        quickSort(arr, low, p - 1); 
        quickSort(arr, p + 1, high); 
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
		
	quickSort(a,0,n-1);
	for( i=0;i<n;i++) fprintf(ft,"%d ",a[i]);
   }
}
	
	
