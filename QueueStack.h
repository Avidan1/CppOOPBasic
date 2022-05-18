/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/

#pragma once
#ifndef QUEUESTACK_H
#define QUEUESTACK_H
#include "Queue.h"
#include "StackList.h"
class QueueStack : public Queue {
private:
	void drainStackToStack(Stack* st1, Stack* st2);//private fucntion to drain stack to another stack
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() const override;
	bool isEmpty() const override;
};
#endif


