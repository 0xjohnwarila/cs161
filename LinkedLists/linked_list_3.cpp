#include <iostream>
using std::cout;
using std::endl;

template<class T>
class list{
private:
	class node{
	public:
		T value;
		node *next;
		node *prev;

		node():node(T()){}
		node(T value): node(value, this, this){}
		node(T value, node *next, node *prev): value(value), next(next), prev(prev){}

		void insert(node *other){
			next = other;
			prev = other -> prev;
			next -> prev = prev -> next = this;
		}
	};

	class iterator{
	private:
		node *cur;
	public:
		iterator(const iterator &i): cur(i.cur){}
		iterator(node *n): cur(n){}

		bool operator == (const iterator &i){return cur == i.cur;}
		bool operator != (const iterator &i){return cur != i.cur;}

		T& operator*(){return cur -> value;}

		iterator& operator++(){
			cur = cur -> next;
			return *this;
		}

		iterator operator++(int){
			iterator clone(this);
			cur = cur -> next;
			return clone;
		}
	};

	node *head;
public:
	list(): head(new node()){}
	void insert(T value){
		(new node(value)) -> insert(head->next);
	}
	void append(T value){
		(new node(value)) -> insert(head);
	}
	iterator begin(){return iterator(head -> next);}
	iterator end(){return iterator(head);}
};

int main(int argc, char const *argv[])
{
	list<int> l;
	l.insert(3);
	l.append(5);
	
	for(auto v:l)
		std::cout<< v << std::endl;

	return 0;
}