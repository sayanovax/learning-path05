#include<stdio.h>
#include<math.h>
#define f(x) pow(x,x)+x-4
void main()
{
	float a , b ,c,fa,fb,fc;
	
	printf("enter the value of a:");
	scanf("%f",&a);
	printf("enter the value of b:");
	scanf("%f",&b);
	do{
		fa = f(a);
	    fb = f(b);
	    fc = f(c);
		c= a-((fa*(a-b))/(fa-fb));
		b=a;
		a=c;
	}
	while(fabs(fc)>0.001);
	printf("the root is:%f",c);
}
