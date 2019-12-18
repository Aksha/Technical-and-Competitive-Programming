/*

#Generate prime numbers in a range. 

Sieve of Eratosthenes
1) Start with an index at the first prime: 2

2) For each identified prime number, mark all multiples of the 
prime as composite.

3) Increment the index and check to see whether the number 
has been marked as a composite. If not marked, it is a prime. 
If marked, it is a composite and can be skipped.

The figure below represents the algorithm in progress.

    2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |12 …
    P         C         C         C         C        C
    ^

    2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |12 …
    P    P    C         C         C    C    C        C
         ^     (already marked OK)

    2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 |12 …
    P    P    C         C         C    C    C        C
              ^ -- skip

Write code that takes a number n and produces all prime numbers < n.
For n=20, the output should be: [2, 3, 5, 7, 11, 13, 17, 19].

  |primes < 100| = 25
  |primes < 1000| = 168

 */
 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> computePrime(int n) {
  vector <int> primeNumbers;
  unordered_map <int, char> numberCount;
  if(n < 2)
    return primeNumbers; 
  for(int i = 0; i < n; i++) {
    numberCount[i] = 'O';
  }
  for( int i = 2; i < n; i++) {
    if(numberCount[i] == 'O') {
      numberCount[i] = 'P'; //numberCount: {{2,'P'},}
      primeNumbers.push_back(i); //primeNumbers: {2,
      for(int j = 2*i; j < n; j += i) {
        numberCount[j] = 'C'; // numberCount: {{2,'P'},{4,'C'},{6,'C'},{8,'C'}} {4,6,8}
      }   
    }
    else if(numberCount[i] == 'C') {
      continue;
    }
  }
  return primeNumbers;
}
// To execute C++, please define "int main()"
int main() {
  int n = 1000;
  vector <int> primeNumbers = computePrime(n);
  int size = primeNumbers.size();
  cout << size << endl;
  cout << "The prime numbers less than n are : " << endl;
  for(int i = 0; i < size; i++) {
    cout << primeNumbers[i] << " ";
  }
  return 0;
}
