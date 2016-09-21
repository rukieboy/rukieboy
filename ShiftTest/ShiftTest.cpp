#include <iostream>
#include <string>

using namespace std;

int main()
{


	cout<<" Shift Test"<<endl;
	
	int inputNum;
	int shiftNum;
	
	cout<< " insert inputNum "; 
	cin>> inputNum;
	
	cout<<" input = "<< inputNum << endl;

	cout<< " insert shiftNum "; 
	cin>> shiftNum;


	int shiftedNum;

	shiftedNum = inputNum >> shiftNum;
	
	cout<<" Shifted Number ( "<< inputNum << " >> " << shiftNum << " ) = " << shiftedNum <<endl; 

	
	


	return 0;
}
