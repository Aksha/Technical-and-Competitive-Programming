#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    
    vector<int> numbers = {1,72,20,10,0};
    vector<string> words = {"hi", "how", "are", "you"};
    priority_queue<int> pq;

    cout << "Descending order : " << endl;
    cout << "Integer: " << endl;

    for(int i = 0; i < numbers.size(); i++) {
        pq.push(numbers[i]);
    }

    for(int i = 0; i < numbers.size(); i++) {
        cout << pq.top() << endl;
        pq.pop();
    }
    cout << "String : " << endl;

    priority_queue<string> pq1;
    for(int i = 0; i < words.size(); i++) {
        pq1.push(words[i]);
    }

    for(int i = 0; i < words.size(); i++) {
        cout << pq1.top() << endl;
        pq1.pop();
    }

    cout << " Ascending order  : " << endl;
    cout << "Integer: " << endl;
    priority_queue<int,vector<int>, greater<int>> pq2;
    for(int i = 0; i < numbers.size(); i++) {
        pq2.push(numbers[i]);
    }

    for(int i = 0; i < numbers.size(); i++) {
        cout << pq2.top() << endl;
        pq2.pop();
    }
    priority_queue<string,vector<string>, greater<string>> pq3;
    for(int i = 0; i < words.size(); i++) {
        pq3.push(words[i]);
    }
    cout << "String : " << endl;
    for(int i = 0; i < words.size(); i++) {
        cout << pq3.top() << endl;
        pq3.pop();
    }
    return 0;
}
