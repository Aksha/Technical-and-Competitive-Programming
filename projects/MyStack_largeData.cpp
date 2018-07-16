#include <iostream>
#include <cstdlib>

#define NELEM 1000000000

using namespace std;

struct elem_t {
    int value;
    int other;
    elem_t() {};
    elem_t(int value, int other) : value(value), other(other) {}
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
	cout << "Element: " << count <<  "pushed to Stack" << endl;
    }
    else {
        tail->data = val;
        tail->next = newNode();
        tail->next->prev = tail;
        tail = tail->next;
	count++;
        cout << " Element " << count << " pushed to stack:" << endl;
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
	MyStack s; 

	/*
	elem_t* elem = new elem_t(10, 10 >> 1);
	s.push(elem);
	elem_t* elem1 = new elem_t(20, 20 >> 1);
	s.push(elem1);
	elem_t* elem2 = new elem_t(2, 2 >> 1);
	s.push(elem2);
	cout << "The size is : " << s.size() << endl;
	elem_t* element = static_cast<struct elem_t*>(s.pop());
	cout << "The popped element is: " <<  element->value << " " <<element->other << endl;	
	elem_t* element1 = static_cast<struct elem_t*>(s.pop());
	cout << "The popped element is: " <<  element1->value << " " << element1->other << endl;
	elem_t* element2 = static_cast<struct elem_t*>(s.pop());
        cout << "The popped element is: " <<  element2->value << " " << element2->other << endl;
	cout << "The size now: " << s.size() << endl;
	elem_t* element3 = static_cast<struct elem_t*>(s.pop());
        cout << "The popped element is: " <<  element3->value << " " << element3->other << endl;
	#define NELEM 1000 000 000
                int i;
                for (i = 0; i < NELEM; i++) {
                                elem_t* elem = (elem_t*) malloc (sizeof(elem_t*));
if (elem == NULL) {
                                exit(1);
}
elem -> value = i;
elem -> other = i >> 1;
s -> push(elem);
}
printf(“Stack size : %d \n”, s->size());
 
for ( i = (NELEM – 1); i >= 0; i--) {
                elem_t* elem = s -> pop();
                if (elem -> value != i) {
                                printf (“Error \n”);
}
free(elem);
}
delete s;	

	*/
	for (int i = 0; i < NELEM; i++) {
		elem_t* elem = new elem_t(i , i >> 1);
		if (elem == NULL) {
			exit(1);
		}
		s.push(elem);
	}
	cout << "Stack size : " << s.size();
	for (int i = (NELEM-1); i >= 0; i--) {
		elem_t* elem = static_cast<struct elem_t*>(s.pop()); 
		if (elem->value != i) {
			cout << "Error" << endl;
		}
	}	
	return 0;
}
