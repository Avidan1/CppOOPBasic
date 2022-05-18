/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/

#include "StackList.h"
StackList::StackList()
    : data() {
    // create and initialize a Stack based on Lists
}
StackList::StackList(const StackList& lst)
    : data(lst.data) {    /* copy constructor*/
}


void StackList::clear() {
    // clear all elements from Stack, by setting
    // delete all values from List
    data.clear();
}

bool StackList::isEmpty() const {    // return true if Stack is empty
    return data.isEmpty();
}

int StackList::pop() {
    // return and remove the topmost element in the Stack
    // get first element in List
    int result = data.firstElement();
    // remove element from List
    data.removeFirst();
    // return value
    return result;
}

void StackList::push(int val) {
    // push new value onto Stack
    data.add(val);
}

int StackList::top() const {
    return data.firstElement();
}
