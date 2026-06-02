#include <iostream>
using namespace std;

int main()
{
 int numbers[20],i;
 int sum = 0;
 cout << "enter 20 numbers:";
 for (i=0; i<20;i++)
 {

  cin >> numbers[i];
}

 cout << "even nos are:";
  for (i=0; i<20;i++)
  {
  	if (numbers[i]%2 == 0)
	  {
	  	cout << numbers[i]<< " ";
  		sum += numbers[i];
	  }
  }
  cout << "\nthe sum of even numbers:"<<sum <<endl;
  return 0;
}
