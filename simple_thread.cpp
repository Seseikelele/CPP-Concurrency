#include <iostream>
#include <thread>

using namespace std;

// void hello()
// {
// 	cout << "Henlo, World!" << endl;
// }

int main()
{
	// thread t(hello);
	thread t([](){cout << "Henlo, World!" << endl;});
	t.join();
}