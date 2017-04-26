//#include "CppTest.h"
#include <CppTest.h>

using namespace std;

int main( int argc, char **argv ) 
{
//for auto type test and example	
	auto autoString = " Auto Type Test "; // for string
	cout<<"----- cpp test -----"<<endl;
	cout<<"auto to string "<<autoString<<endl;

	auto autoInt = 23; // for integer
	cout<<"auto to Int "<<autoInt<<endl;
// auto type test end

// for lamda test	
	auto f1 = [](int x, int y) {return x + y;};
	cout << " auto and lamda " <<endl;
	cout << " f1(2,3) = "<< f1(2,3)<<endl;

	function<int(int,int)> f2 = [](int x, int y) { return x + y; };
	cout << " f2(2,3) = " <<f2(2,3)<<endl;
// lamda test end

// based for loop test
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "based for loop "<<endl;
	cout << "based default int "<<endl;
	for(auto y : x)
	{
		cout<<y<<" ";
	}
	cout << endl;
	
	vector<int> v = { 1, 2, 3, 4, 5 };
	cout << "based default vector "<<endl;
	for(auto k : v)
	{
		cout<<k<<" ";
	}
	cout << endl;

	cout << "based for loop end "<<endl;
// based for loop test end	


	return 0;
}
