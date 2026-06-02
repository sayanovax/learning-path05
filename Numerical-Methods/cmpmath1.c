#include<stdio.h>
#include<math.h>
#define f(x) sqrt(1-pow(x,3))
void main(){
	int n,i;
	float a,b,h,x ,sum,Integration;
	printf("Enter the lower limit:");
	scanf("%f",&a);
	printf("Enter the upper limit:");
	scanf("%f",&b);
	printf("Enter the no. of sub interval:");
	scanf("%d",&n);
	h=(b-a)/n;
	sum=f(a)+f(b);
	for(i=1;i<n;i++){
	x=a+i*h;
sum=sum+2*f(x);
}
Integration=h*sum/2;
printf("The value of the integration is:%f",Integration);
}
