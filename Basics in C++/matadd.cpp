#include <iostream>
using namespace std;
int main()
{
	int rows , cols,i,j;
	cout << "enter  no. of rows:";
	cin>>rows;
	cout << "enter  no. of cols:";
	cin>>cols;
	
	int mat[rows][cols],mat1[rows][cols],mat2[rows][cols];
	  cout << "enter the elements of the 1st matrix:" << endl;
	  
	  for ( i=0; i< rows; i++)
	  {
	  	for (j=0;j<cols;j++)
	  	{
	  		cout << "enter the value:["<< i <<"]["<< j <<"]:" ;
	  	   cin >> mat[i][j];	
		  }
	  }
	  
     cout << "enter the elements of the 2nd matrix:" << endl;
	  
	  for ( i=0; i< rows; i++)
	  {
	  	for (j=0;j<cols;j++)
	  	{
	  		cout << "enter the value:["<< i <<"]["<< j <<"]:" ;
	  	   cin >> mat1[i][j];
	  	   }
	  }
	  

	  
	  for ( i=0; i< rows; i++)
	  {
	  	for (j=0;j<cols;j++)
	  	{
	  		mat2[i][j] = mat[i][j]+mat1[i][j];
	  	   }
	  }
 
 
	  
	cout << "The matrix after addition is :" << endl;
	  
	  for ( i=0; i< rows; i++)
	  {
	  	for (j=0;j<cols;j++)
	  	{
	  		cout << mat2[i][j] << "\t";
	  	}
	  	cout << endl;
	  }
	  return 0;
}
 
 
