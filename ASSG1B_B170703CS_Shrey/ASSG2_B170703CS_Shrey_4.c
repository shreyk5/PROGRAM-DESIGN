#include<stdio.h>

int main(){
	
	int n;
	scanf("%d",&n);
	
	int a[n];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	int global_max=0;
	int local_max=0;
	int start=0,b;
	
	 for(int i=0;i<n;i++)
     {
       local_max=local_max+a[i];
       if(local_max<0)
       {
	   local_max=0;
       start=i+1;
	   }
       
       if(local_max>global_max)
       {
		 global_max=local_max;
         b=i;
       }
       
     } 
     
	 printf("Largest sum is %d and subarray begins at %d and ends at %d",global_max,start,b);
	
	
	
	
	return 0;
}

