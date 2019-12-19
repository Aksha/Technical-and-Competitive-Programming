#include <iostream>
#include <unordered_map>

using namespace std;
/*
# p = 2 -- prime
# p = 3; (2,4) -- prime
# p = 4; (2,4) (3,6) -- composite
# p = 5; (2,6) (3,6)-- prime
# p = 6; (2,6) (3,6) (5,10) -- composite
# p = 7; (2,8) (3,9) (5,10) -- prime
#      ; (2,8) (3,9) (5,10) (7,14)


1.

Pseudocode:
if(isNotPrime()
When I’m looking at 2, look up primeComposite Pair to see if 2 is a value. If not, add it as prime, find it’s next multiple, add that as a pair.
Else
If the number is found in primeCompositePair,
add key and value and add that as a key value pair
NewComposite = value from the primeComposite Pair just added
currPrime++;
*/

class Prime{
    public:
        int nextComposite = 4;
        int currNum = 2;
        int key = 2;
        int i = 0;
        unordered_map <int, int> primeCompositePair;

        Prime(){}

        bool isComposite(int number) {
            for (auto Composite: primeCompositePair) {
                if (number == Composite.second) {
                    return true;
                }
            }
            return false;
        }

        void howManyComposite(int number) {
            for (auto Composite: primeCompositePair) {
                if (number == Composite.second) {
                    nextComposite = currNum + Composite.first;
                    primeCompositePair[Composite.first] = nextComposite;
                }
            }
        }

        int nextPrime() {
            while(isComposite(currNum)) {
                howManyComposite(currNum);
                currNum++;
            }
            if (primeCompositePair.find(currNum) == primeCompositePair.end()) {
                primeCompositePair.insert(make_pair(currNum, 2 * currNum));
                currNum++;
                return currNum-1;
            }
            else {
                    int compositeValue = currNum + primeCompositePair[currNum];
                    primeCompositePair[currNum] = compositeValue;
                    currNum++;
            }
        }

        void printPrimeComposite() {
            for(auto a:primeCompositePair) {
                cout << "Prime Composite pair : " <<  a.first << ":" << a.second << endl;
            }
        }
};

        int main() {
            Prime p;
            int num = p.nextPrime();
            cout << "first prime: " <<  num << endl;
            p.printPrimeComposite();
            int nextNum = p.nextPrime();
            cout << "next prime 1: " << nextNum << endl;
            p.printPrimeComposite();
            int nextNum2 = p.nextPrime();
            cout << "next prime 2: " << nextNum2 << endl;
            p.printPrimeComposite();
            int nextNum3 = p.nextPrime();
            cout << "next prime 3: " << nextNum3 << endl;
            p.printPrimeComposite();
            int nextNum4 = p.nextPrime();
            cout << "next prime 4: " << nextNum4 << endl;
            p.printPrimeComposite();
            int nextNum5 = p.nextPrime();
            cout << "next prime 4: " << nextNum5 << endl;
            p.printPrimeComposite();
            return 0;
        }
