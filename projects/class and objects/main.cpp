#include <iostream>
#include <cstdlib>
#include "MyStack_class.h"

#define NELEM 1000

using namespace std;

void
example() {
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
}

int
main()
{
	example();
        return 0;
}
