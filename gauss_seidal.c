#include <stdio.h>
#include <math.h>
#define f1(x1,x2,x3) (7-x2-x3)/3
#define f2(x1,x2,x3) (9.4-x1-x3)/4
#define f3(x1,x2,x3) (13-2*x1-x2)/5
void main()
{
	float x1,x2,x3,y1,y2,y3,e1,e2,e3;
	x1=0;
	x2=0;
	x3=0;
	do
	{
		y1 = f1(x1,x2,x3);
		y2 = f2(y1,x2,x3);
		y3 = f3(y1,y2,x3);
		
		e1 = (y1-x1);
		e2 = (y2-x2);
		e3 = (y3-x3);
		x1=y1;
		x2=y2;
		x3=y3;	
		
	}while((fabs(e1)>0.001) && (fabs(e2)>0.001) && (fabs(e3)>0.001));
	printf("the value of x1:%f\n",x1);
	printf("the value of x2:%f\n",x2);
	printf("the value of x3:%f\n",x3);
	
}
