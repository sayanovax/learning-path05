#include <iostream>
using namespace std;

int fibo (int num)
{
	if ( num ==0 || num==1)
	{
		return num;
    }
    return fibo(num-1)+fibo(num -2);
}

int main ()
{
	int num,i;
	cout << "enter the no. of terms:";
	cin >> num;
	cout << " the fibonacci series:";
	for (i =0; i < num ; i++)
	{
		cout << fibo(i)<< " " ;
		}
		return 0 ;
}
