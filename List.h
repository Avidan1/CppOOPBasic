/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/
#include <iostream>
#pragma once
#ifndef LIST_H
#define LIST_H


using namespace std;
class List {
public:
	class Link {
	public:
		Link(const Link&); // constructor
		Link(int linkValue, Link* nextPtr);
		int value;  // data areas
		Link* next;
	};	 //end of class Link

	List();  // constructors
	List(const List&);
	~List();
	int firstElement()  const;  // operations
	void add(int value);
	void clear();
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	List& operator=(const List& fromList);
	friend ostream& operator<<(ostream& os, const List& pList);
	friend istream& operator>>(istream& is, List& gList);
	void insert(int key);
	void remove(int key);
protected: 	Link* head;  // data field	
};
#endif // LIST_H