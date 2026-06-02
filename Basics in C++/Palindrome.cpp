#include <iostream>
#include<string>
using namespace std;
int main ()
{
  string str , rev ="";
  cout << "enter a string or num:";
  cin >> str;
  for (int i =str.length()-1; i>=0; i--)
  {
  	rev += str[i];
  }	
  if (str==rev)
   cout << str << "  is a palindrome"<< endl;
   else 
   cout << str << "is not a palindrome" << endl;
   return 0;
}
