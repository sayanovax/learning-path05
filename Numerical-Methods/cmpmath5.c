#include <stdio.h>
#include <math.h>
#define f(x) pow(x,x)+x-4
void main ()
{
	float a,b,c,fa,fb,fc;
	printf("Enter the value of a :");
	scanf("%f",& a);
	printf("Enter the value of b :");
	scanf("%f",& b);
	do{
		fa=f(a);
		fb=f(b);
		fc=f(c);
		c=b-((fb*(b-a))/(fb-fa));
		a=b;
		b=c;
	}
	while(fabs(fc)>0.001);
	printf("The root is:%f", c);
}
