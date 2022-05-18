/*
Authers:Avidan Maatuk 318482247
and Eldad Cohen 207920711(we submit togther)
Name Of The Course: C++ WorkShop
Assignment:8
Question : 2
Info about the app :this use implenmt Queue with stack(that implement by list-the one that shown to us in class)
*/

#include "List.h"

List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}//P-ctor of link class

List::Link::Link(const Link& source) ://C-ctor of Link class
	value(source.value), next(source.next) {
}

//-----------------------------------

List::List() : head(nullptr) {}//E-Ctor of List

List::List(const List& l) {//C-ctor of list class(Deep copy)
	Link* src, * trg;
	if (l.head == nullptr)//
		head = nullptr;
	else {
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr) {
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}

List::~List() {
	clear();
}
//clear all list function
void List::clear() {   // empty all elements from the List
	Link* next;
	for (Link* p = head; p != nullptr; p = next) {
		next = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}
//isEmpty function retunr true if empty
bool List::isEmpty() const {
	return head == nullptr;
}
//function that add a new value to the front of a Linked List
void List::add(int val) {
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}
//fucntion that return the value of the first element of list
int List::firstElement() const {
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

//fucntion that return true if the value she get is in the list 
bool  List::search(const  int& val) const {
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


//function the remove the first element in list
void List::removeFirst() {
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}
//oveload operator= - make deep copy
List& List::operator=(const List& fromList) {
	this->clear();//clear the current list so we can fill it from the start
	if (fromList.isEmpty())//if we try to copy empty list
		return *this;
	Link* endOfFromList = fromList.head;//pointer that will be our indecate where our we in the list we want to copy from her
	head = new Link(endOfFromList->value, nullptr);//set the head of the 
	endOfFromList = endOfFromList->next;//move forward in the from list
	Link* endOfGetList = head;//pointer to the end of the list we want to copy to her
	while (endOfFromList != nullptr) {//to see we copy all the fromlist and nothing more or less 
		endOfGetList->next = new Link(endOfFromList->value, nullptr);//creating nodes of the getlist by the value of the fromlist element by order
		endOfFromList = endOfFromList->next;//move forward in the from list
		endOfGetList = endOfGetList->next;//move the pointer to the end of the getlist
	}

	return *this;
}
//insert function - get int and put i the the right place in ordered list (that go down(not strong down))
void List::insert(int key) {
	Link* temp = head;//pointer so we can move on the list to see where to put the value
	if (this->isEmpty() || temp->value < key) //check with the first element
		this->add(key);
	else {
		while (temp->next != nullptr && key < temp->next->value) {//check where to put
			temp = temp->next;//count to see where to put the int
		}
		temp->next = new Link(key, temp->next);//put the int in the right place
	}
}
//functuion that get int and remove the first element of that int from the list -if the int not found throw exption
void List::remove(int key) {
	Link* temp = head;
	Link* saveTheLast = head;
	if (this->isEmpty()) {
		throw("value not found");
	}
	if (temp->value == key)
		this->removeFirst();
	else {
		temp = temp->next;
		while (temp != nullptr && temp->value != key) {
			saveTheLast = saveTheLast->next;//save the one before the removed int
			temp = temp->next;//pointer indiction to the list we going throw
		}
		if (temp == nullptr) {//if we doesnt found
			throw("value not found");
		}
		else if (temp->value == key) {//if we found remove without losing toch to the other elements of the list
			saveTheLast->next = temp->next;
			temp->next = nullptr;
			delete temp;

		}
		else {
			throw("value not found");
		}
	}
}
//overload operator << - print all the list with space between the elements
ostream& operator<<(ostream& os, const List& pList) {
	List::Link* temp = pList.head;
	while (temp != nullptr) {
		os << temp->value << " ";
		temp = temp->next;
	}
	return os;
}
//overload operator >> - get strong down series of number to list until it doesn't exsist the condtion of down series
istream& operator>>(istream& is, List& gList) {
	gList.clear();
	int inputValue;
	is >> inputValue;
	gList.head = new List::Link(inputValue, nullptr);
	List::Link* pToTheEnd = gList.head;
	is >> inputValue;
	while (inputValue < pToTheEnd->value) {//check the series condtion
		pToTheEnd->next = new List::Link(inputValue, nullptr);
		pToTheEnd = pToTheEnd->next;
		is >> inputValue;
	}
	return is;
}
