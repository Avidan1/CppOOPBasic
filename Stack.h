/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/

#pragma once
#ifndef STACK_H
#define STACK_H
class Stack {
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual int pop() = 0;
    virtual void push(int value) = 0;
    virtual int top() const = 0;
};
#endif

