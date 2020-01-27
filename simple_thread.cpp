#include <iostream>
#include <thread>

using namespace std;

void hello()
{
	cout << "Hello from the other thread." << endl;
}

int main()
{
	cout << "Hello from the main thread." << endl;
	thread t1(hello);
	thread t2([](){cout << "Hello from the other other thread." << endl;});
	t1.join();
	t2.join();
}