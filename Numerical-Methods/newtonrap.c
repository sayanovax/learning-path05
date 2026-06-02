#include<stdio.h>
#include<math.h>
#define f(x) x+log(x)-2
#define g(x) 1+1/x
void main()
{
	float x,f,g;

	printf("enter the initial guess of th root:");
	scanf("%f",&x);
	do{
			f = f(x);
	        g = g(x);
		x = x-(f/g);
	}
	while(fabs(f)>0.001);
	printf("the root is : %f",x);
	
}
