#include <iostream>
using std::cout;
using std::endl;

template<class T>

class node{
public:
	T value;
	node *next;
	node *prev;

	node(T value, node *next, node *prev): value(value), next(next), prev(prev){}
	node(T value): node(value, this, this){}

	void insert(node *other);
};

template<class T>

class list{
private:
	node<T> head;
public:
	list(): head(0){}
	void insert(T value);
	void append(T value);
	void dump(void);
};

void node::insert(node *other){
	next = other;
	prev = other -> prev;
	next -> prev = prev -> next = this;
}

void list::insert(T value){
	(new node(value)) -> insert(head.next);
}

template<class T>
void list::append(T value){
	(                                                                                                                                                                                                                                                                      new node(value)) -> insert(&head);
}

template<class T>
void list::dump(void){
	for(node<T> *temp = head.next; temp != &head; temp = temp -> next){
		cout << temp -> value << endl;
	}
}

int main(int argc, char const *argv[])
{
	list<int> l;

	l.append(5);
	l.append(3);
	l.append(89);
	l.insert(7);

	l.dump();

	return 0;
}