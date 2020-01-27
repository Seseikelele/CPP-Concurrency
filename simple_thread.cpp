#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void hello()
{
	cout << "Hello from the other thread." << endl;
}

class Task
{
public:
	void operator()() const
	{
		cout << "I am a task." << endl;
	}
};

int main()
{
	cout << "Hello from the main thread." << endl;
	thread t1(hello);
	thread t2([](){cout << "Hello from the other other thread." << endl;});
	Task task;
	thread t3(task);
	thread t4((Task()));
	thread t5{Task()};
	thread t6([](){
		sleep(1);
		cout << "Sleepy hello." << endl;
	});
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.detach();
}