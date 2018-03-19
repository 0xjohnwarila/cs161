#include <iostream>
using std::cout;
using std::endl;

struct node{
	int value;
	node *next;
	node(int value): value(value), next(NULL){};
	node(int value, node *next): value(value), next(next){}
};

class list{
private:
	node *head;
	node *tail;
public:
	list():head(NULL), tail(NULL){}
	void insert(int value);
	void dump(void);
	void append(int value);

};

void list::insert(int value){
	head = new node(value, head);
	if(!tail){
		tail = head;
	}
}

void list::append(int value){
	if(head){
		
		tail = tail -> next = new node(value);
	}else{
		tail = head = new node(value);
	}
}

void list::dump(void){
	node *n = head;

	for(node *n = head; n; n = n -> next){
		cout << n -> value << endl;
	}
}

int main(int argc, char const *argv[])
{
	list l;

	l.append(5);
	l.append(3);
	l.append(89);
	l.insert(7);

	l.dump();

	return 0;
}