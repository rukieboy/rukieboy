#include <iostream>
#include <string>

using namespace std;

#define MOD(x,y)			   ((x) & ((y)-1))

int main()
{


	cout<<" Mod Test"<<endl;
	
	int inputNumX;
	int inputNumY;
	
	cout<< " insert inputNum X"; 
	cin>> inputNumX;
	
	cout<<" input X= "<< inputNumX << endl;

	cout<< " insert inputNum Y"; 
	cin>> inputNumY;
	cout<<" input Y= "<< inputNumY << endl;

	int modedNum;

	modedNum = MOD(inputNumX,inputNumY);
	
	cout<<" Moded Number MOD( "<< inputNumX << ", " << inputNumY << " ) = " << modedNum <<endl; 

	
	


	return 0;
}
