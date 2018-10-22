#include<stdio.h>
#include<stdlib.h>

struct node
{	
	int data;
    struct node *next;	
};

struct list
{
	struct node *first_address;
	struct node *last_address;
    int number;	
};

int divi(int n)
{
	int divisor = 1, temp = n;
    
    while (n> 0) {
        n /= 10;
        divisor *=10;
    }

    return (temp == 0) ? 1 : divisor;
	
}

void bucket_sort(int *arr,int n,int max)
{
	struct list bucket[n];
	//bucket = (struct list *)malloc(sizeof(struct list)*n);
	
	
    int divisor=divi(max);
    int i;
    
    for(i=0;i<n;i++)
    {
    	bucket[i].first_address=NULL;
    	bucket[i].last_address=NULL;
    	bucket[i].number=0;
	}
	
	//Insert elements into resp. buckets
	int index;
	for(i=0;i<n;i++)
	{
		index=(arr[i]*n)/divisor;
		
		if(bucket[index].first_address==NULL||bucket[index].last_address==NULL)
		{
			struct node *new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=arr[i];
			new_node->next=NULL;
			
			bucket[index].first_address=new_node;
			bucket[index].last_address=new_node;
			bucket[index].number=1;
		}
		
		else
		{
			struct node *new_node=(struct node*)malloc(sizeof(struct node));
			new_node->data=arr[i];
			new_node->next=NULL;
                        (bucket[index].last_address)->next=new_node;
			bucket[index].last_address=new_node;
			bucket[index].number=bucket[index].number+1;
		}
		
	}
	
	  for(i=0;i<n;i++)
	  {
	  	
	  	int temp[bucket[i].number];
	  	struct node *temp_node=bucket[i].first_address;
	  	   
	  	for(int j=0;j<bucket[i].number;j++)  //copy the list to a temp_array
	  	{
	  	    temp[j]=temp_node->data;	
	  		temp_node=temp_node->next;
		}
       	//Now applying insertion sort for sorting each bucket individually
	  	   for (int j = 1; j<bucket[i].number;++j)
		   {
                int key = temp[j];
                int k = (j - 1);
                
                while (k>=0 && temp[k]>key)
				{
                    temp[k + 1] = temp[k];
                    --k;
                }
                
                temp[k + 1] = key;
            }
	  	
	  	temp_node=bucket[i].first_address;
	  	int j = 0;
	  	 
         while (temp_node!= NULL)
		{
                temp_node->data = temp[j];
                ++j;
                temp_node = temp_node->next;
          }	
	  }
	  //NOW COPYING BACK TO THE ARRAY
     int j = 0;
    for (i = 0; i < n; ++i)
	{
    
        if (bucket[i].first_address != NULL && bucket[i].last_address != NULL)
		{
            struct node * temp_node = bucket[i].first_address;
            while (temp_node != NULL)
			{
                arr[j] = temp_node -> data;
                ++j;
                temp_node = temp_node-> next;
             }
         }
     }

}

int main()
{
	int n=0;
      FILE *fp=fopen("buckin.txt","r");  
  
    int arr[100000];
  
    int max=0;
    while(fscanf(fp,"%d",&arr[n])!=EOF)
   {  
     if(max<arr[n])
       max=arr[n];
      n++;
   }
 	
	bucket_sort(arr,n,max);
	
	for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
		
	return 0;
}


	
	
	

