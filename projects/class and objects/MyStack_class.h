#ifndef MYSTACK_CLASS_H
#define MYSTACK_CLASS_H

class elem_t {
    public:
        int value;
        int other;
        elem_t() {};
        elem_t(int value, int other) : value(value), other(other) {}
        ~elem_t() {};
};

class MyStack {
        private:
                void* data;
                MyStack* next;
                MyStack* prev;
        public:
                MyStack () {}
                MyStack(void* val) : data(val), next(nullptr), prev(nullptr) {}
                ~MyStack() {}
                MyStack* newNode();
                MyStack* newNode(void*);
                void push(void*);
                void* pop();
                int size();
};

#endif
