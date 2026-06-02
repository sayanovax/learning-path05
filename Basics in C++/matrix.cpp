#include <iostream>
using namespace std;
int main()
{
	int rows , cols,i,j;
	cout << "enter  no. of rows:";
	cin>>rows;
	cout << "enter  no. of cols:";
	cin>>cols;
	
	int mat[rows][cols];
	  cout << "enter the elements of the matrix:" << endl;
	  
	  for ( i=0; i< rows; i++)
	  {
	  	for (j=0;j<cols;j++)
	  	{
	  		cout << "enter the value:["<< i <<"]["<< j <<"]:" ;
	  	   cin >> mat[i][j];	
		  }
	  }
	  
	cout << "The matrix is :" << endl;
	  
	  for ( i=0; i< rows; i++)
	  {
	  	for (j=0;j<cols;j++)
	  	{
	  		cout << mat[i][j] << "\t";
	  	}
	  	cout << endl;
	  }
	  return 0;
}
 
 
