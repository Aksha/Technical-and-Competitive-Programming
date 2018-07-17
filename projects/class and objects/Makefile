MyStack_class: MyStack_class.o main.o
	g++ MyStack_class.o main.o -o MyStack_class

MyStack_class.o: MyStack_class.cpp main.cpp
	g++ -c -std=c++0x MyStack_class.cpp main.cpp

clean:
	rm MyStack_class.o main.o MyStack_class 
