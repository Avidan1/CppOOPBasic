/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
class Queue {
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front() const= 0;
    virtual bool isEmpty() const = 0;
};
#endif

