//map ver 0.1
#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
   map<int, string> Employees;
   // 1) Assignment using array index notation
   Employees[5234] = "Mike C."; // = Employees["Mike C."] = 5234;
   Employees[3374] = "Charlie M."; // = Employees["Charlie M."] = 3374;
   Employees[1923] = "David D."; // = Employees.insert(std::pair<string,int>("David D.",1923));
   Employees[7582] = "John A."; // = Employees.insert(map<string,int>::value_type("John A.",7582));
   Employees[5328] = "Peter Q."; // = Employees.insert(std::make_pair("Peter Q.",5328));
   
   cout << "Employees[3374]=" << Employees[3374] << endl << endl;

   cout << "Map size: " << Employees.size() << endl;

   for( map<int,string>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }

}