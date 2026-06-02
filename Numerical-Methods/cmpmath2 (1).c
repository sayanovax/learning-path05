#include<stdio.h>
#include<math.h>
#define f(x) sqrt(1-pow(x,3))
void main(){
	int n,i;
	float a,b,h,x,integration,sum;
	printf("Enter the lower limit:");
	scanf("%f",&a);
	printf("Enter the upper limit:");
	scanf("%f",&b);
	printf("Enter the no. of sub intervals:");
	scanf("%d",&n);
	h=(b-a)/n;
	sum=f(a)+f(b);
	for(i=1;i<n;i++){
	x=a+i*h;
	if(i%2==0){
		sum=sum+2*f(x);
	}
	else{
		sum=sum+4*f(x);
	}
	}
	integration=h*sum/3;
	printf("The value of integration is:%f",integration);
}
