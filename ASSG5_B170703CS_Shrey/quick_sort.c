#include<stdio.h>

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

int main()
{
	
	int arr[6]={4,3,1,11,1,0};
	quickSort(arr,0,5);
	int i;
	for(i=0;i<6;i++)
	 printf("%d ",arr[i]);	
	
	
	
}
