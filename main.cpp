/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/

#include <iostream>
#include "QueueStack.h"
using namespace std;
int main() {
	Queue* Q;
	int num;
	Q = new QueueStack();
	cout << "enter 5 numbers: " << endl;
	try {
		for (int i = 0; i < 5; i++) {
			cin >> num;
			Q->enqueue(num);
		}
	}
	catch (const char* msg) {
		cout << msg;
	}
	cout << "first in queue is: " << Q->front() << endl;
	cout << "removing first 2 elements:" << endl;
	cout << Q->dequeue() << ' ';
	cout << Q->dequeue() << endl;
	cout << "first in queue is: " << Q->front() << endl;
	Q->enqueue(8);
	Q->enqueue(9);
	cout << "emptying out the queue: " << endl;
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	cout << endl;
	return 0;
}

/*
enter 5 numbers:
1 2 3 4 5
first in queue is: 1
removing first 2 elements:
1 2
first in queue is: 3
emptying out the queue:
3 4 5 8 9
*/