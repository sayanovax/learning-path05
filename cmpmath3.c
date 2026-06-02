#include <stdio.h>
#include <math.h>
#define f(x) x+log(x)-2
void main()
{
	float a,b,c,fa,fb,fc;
	fa=f(a);
	fb=f(b);
	printf("Enter the value of a :");
	scanf("%f",&a);
	printf("Enter the value of b :");
	scanf("%f",&b);
	do{
	c=(a+b)/2;
	fc=f(c);
	if(fa*fc<0){
		b=c;
		fb=fc;
	}
	else{
		a=c;
		fa=fc;
	}
	}
	while(fabs(fc)>0.001);	
	printf("The root is :%f",c);
}
