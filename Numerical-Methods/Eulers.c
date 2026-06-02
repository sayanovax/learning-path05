#include <stdio.h>
#include <math.h>
#define f(x,y) x+sqrt(y)
void main()
{
	float h,x0,y0,xn,yn,f1;
	int n,i;
	printf("enter the value of h:");
	scanf("%f",&h);
	printf("enter the value of x0:");
	scanf("%f",&x0);
	printf("enter the value of y0:");
	scanf("%f",&y0);
	printf("enter the value of xn:");
	scanf("%f",&xn);
	n = (xn-x0)/h;
	for(i=1;i<=n;i++)
	{
		f1 = f(x0,y0);
	  yn = y0+h*f1;	
	  x0=x0+h;
	  y0=yn;
	}
printf("the value of yn:%f",xn,yn);
}










