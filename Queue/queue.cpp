//queue ver 0.1
#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> Queue;

	for(int i=0 ; i<10; i++)
	{
		Queue.push(i);
	}
	cout << Queue.front() << endl;
	Queue.pop();
	cout << Queue.front() << endl;
	
	return 0;
}