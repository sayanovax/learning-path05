#include <iostream>
using namespace std;
int main ()
{
	int n,i,j ;
	cout << " enter size of sq matrix:";
	cin >> n ;
	int mat [n][n];
	bool isIdentity = true ;
	cout << " enter elements of matrix:" << endl;
	for ( i=0; i<n; i++)
	  {
	  	for (j=0;j<n;j++)
	  	{
	  		cin >> mat[i][j];
	  	}
      }
      
   for ( i=0; i<n; i++)
   {
	  	for (j=0;j<n;j++)
	  	{ 
	  	   if (i==j)
	  	   {
	  		  if (mat[i][j]!=1)
	  		  {
	  		    isIdentity = false;
	  		    break;
			  }
	       }
		   	 else 
		  	 {
	  		   if (mat[i][j]!=0)
	  		   	  {
	  			   isIdentity = false;
   			       break;
		          }
             }
  	     }
		  
  	 }
  	 
  	 if (isIdentity)
  	 cout<< "it is an identity matrix:" << endl;
  	 else
  	  cout<< "it is not an identity matrix:" << endl;
  	  return 0;
}
