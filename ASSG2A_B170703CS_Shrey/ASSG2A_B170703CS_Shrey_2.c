#include<stdio.h>

#include<string.h>
#include<math.h>

void binary_decimal(char c[])
{

int flag=1;
int t;
float decimal=0;

	for(int i=0;i<strlen(c);i++)
	{
            if(c[i]=='.')
              {  flag=0; t=i; break;}
         }

         if(flag==0)
       {          
	for(int i=t-1;i>=0;i--)     
          decimal=decimal+((c[i]-48)*(pow(2,t-1-i)));
          
           for(int i=t+1;i<strlen(c);i++)
             decimal=decimal+((c[i]-48)*(pow(2,t-i)));
       }
	else 
     	for(int i=strlen(c)-1;i>=0;i--)
          decimal=decimal+((c[i]-48)*(pow(2,strlen(c)-i-1)));
  

printf("Equivalent decimal number is %f",decimal);

}

int main()
{

char c[100000];
printf("Enter a binary number");
int count=0;

scanf("%s",c);
binary_decimal(c);

return 0;
}
