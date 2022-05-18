/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/

#include "QueueStack.h"

void QueueStack::drainStackToStack(Stack* st1, Stack* st2) {
    while (!st1->isEmpty()) {
        st2->push(st1->pop());
    }
}

QueueStack::QueueStack() {
    data = new StackList();
}

void QueueStack::clear() {
    if (data)
        data->clear();
}

int QueueStack::dequeue() {
    if (!data->isEmpty())
        return data->pop();
    throw("empty queue");
}

void QueueStack::enqueue(int value) {
    Stack* temp = new StackList();
    if (data->isEmpty()) {//check for first element 
        data->push(value);
    }
    else {
        drainStackToStack(data, temp);
        data->push(value);//put the value in the end of the queue
        drainStackToStack(temp, data);
    }
    
}

int QueueStack::front() const{
    if (!data->isEmpty())
        return data->top();
    throw("empty queue");
}

bool QueueStack::isEmpty() const {
    return data->isEmpty();
}
