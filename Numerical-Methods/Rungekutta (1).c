#include <stdio.h>
#include <math.h>
#define f(x,y) (sqrt(x+y))
void main()
{
	float h,x0,y0,xn,yn,k1,k2,k3,k4,k,f1,f2,f3,f4;
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
	  f1= f(x0,y0);
	  k1=h*f1;
	  f2= f(x0+h/2,y0+k1/2);
	  k2= h*f2;
	  f3= f(x0+h/2,y0+k2/2);
	  k3= h*f3;
	  f4= f(x0+h,y0+k3);
	   k4=h*f4;
	 k=(k1+2*k2+2*k3+k4)/6;
	  yn=y0+k;	
	  x0=x0+h;
	  y0=yn;
	}
   printf("the value of yn:%f",yn);
}










