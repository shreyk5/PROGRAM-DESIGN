#include<stdio.h>
int main(){

int x;
long long ans=1;
scanf("%d",&x);

for(int i=1;i<=x;i++){
ans=ans*i;

}
printf("Factorial of x=");
printf("%lld",ans);









return 0;
}
