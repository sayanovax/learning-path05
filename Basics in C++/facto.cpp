#include <iostream>
using namespace std;

int fact (int num)
{
	if ( num ==0 || num==1)
	{
		return num;
	}
	return num * fact(num-1);
}

int main ()
{
	int num;
	cout << "enter the number:";
	cin >> num;
	
	cout << "Factorial is :" << fact(num);
}

