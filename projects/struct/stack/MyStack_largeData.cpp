#include <iostream>
#include <cstdlib>

#define NELEM 1000000000

using namespace std;

struct elem_t {
    int value;
    int other;
    elem_t() {};
    elem_t(int value, int other) : value(value), other(other) {}
    ~elem_t() {};
};

struct MyStack {
	void* data;
	MyStack* next;
	MyStack* prev;
	MyStack () {}
	MyStack(void* val) : data(val), next(nullptr), prev(nullptr) {}
	~MyStack() {}
	MyStack* newNode();
	MyStack* newNode(void*);
	void push(void*);
	void* pop();
	int size();
};

int count = 0;
MyStack* root = new MyStack();
MyStack* tail = new MyStack();;

MyStack* MyStack::newNode()
{
    MyStack* stackNode;
    stackNode = new MyStack();
    stackNode->data = NULL;
    stackNode->next = NULL;
    stackNode->prev = NULL;
    return stackNode;
}

MyStack* MyStack::newNode(void* data)
{
    MyStack* stackNode;
    stackNode = new MyStack(data);
    stackNode->data = data;
    stackNode->next = NULL;
    stackNode->prev = NULL;
    return stackNode;
}

void MyStack::push (void* val)
{
    if (count == 0) {
        root = newNode(val);
        tail = newNode(val);
        tail->next = newNode();
        tail = tail->next;
        root->next = tail;
        tail->prev = root;
	count++;
	cout << "Element: " << count <<  " pushed to Stack" << endl;
    }
    else {
        tail->data = val;
        tail->next = newNode();
        tail->next->prev = tail;
        tail = tail->next;
	count++;
        cout << " Element " << count << " pushed to stack" << endl;
    }
}

void*  MyStack::pop() 
{
    if (count == 0) {
        cout << "Stack is empty" << endl;
        exit(1);
    }
    MyStack* evictedN = new MyStack();
    tail = tail->prev;
    evictedN = tail;
    tail->next = tail->next->prev = NULL;
    count--;
    return evictedN->data;
}

int MyStack::size() {
	int cnt = 0;
	while(root->next != NULL) {
		cnt++;
		root = root->next;
	}
	return cnt;
}

int 
main() 
{
	MyStack* s = new MyStack; 
	for (int i = 0; i < NELEM; i++) {
		elem_t* elem = new elem_t(i , i >> 1);
		if (elem == NULL) {
			exit(1);
		}
		s->push(elem);
		cout << "the pushed element's value and other respectively : " <<  elem->value << " " << elem->other << endl;
	}
	cout << "Stack size : " << s->size() << endl;
	for (int i = (NELEM-1); i > 0; i--) {
		elem_t* elem = static_cast<struct elem_t*>(s->pop()); 
		if (elem->value != i) {
			cout << "Error: i is " << i << "and elem-value is " << elem->value << endl;
		}
		cout << "The popped element's value and other respectively: " << elem->value << " " << elem->other << endl;
		delete elem;
	}	
	delete s;
	return 0;
}
