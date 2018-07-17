#include <iostream>
#include "MyStack_class.h"
#include <cstdlib> 

using namespace std;

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

