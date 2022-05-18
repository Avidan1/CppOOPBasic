/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/

#pragma once
#ifndef STACKLIST_H
#define STACKLIST_H
#include "Stack.h"
#include "List.h"	//page 18

//-------------------------------------------------------
//  class StackList
//  Stack implemented using List operations
//-------------------------------------------------------

class StackList : public Stack {
public:
    // constructors
    StackList();
    StackList(const StackList& s);

    // Stack operations
    void clear() override;
    bool isEmpty() const override;
    int pop() override;
    void push(int value) override;
    int top() const override;

protected:
    // data fields
    List data;
};
#endif