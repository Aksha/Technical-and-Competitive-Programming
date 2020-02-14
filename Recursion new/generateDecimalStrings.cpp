/*Generate Decimal Strings of length N

for example... if length is 2, the decimal strings are 0-9 in two positions _ _
10^N is the time complexity.
The sequence is 
00,01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18,19,20,21,.......,89,90,91,92,93,94,95,96,97,98,99
*/

//modifying binary strings problem a bit

#include <iostream>

using namespace std;

void decimalStrings(string slate, int N) {
  if(n == 0)
    cout << slate << endl;
   else {
      decimalStrings(slate + "0", N-1);
      decimalStrings(slate + "1", N-1);
      decimalStrings(slate + "2", N-1);
      decimalStrings(slate + "3", N-1);
      decimalStrings(slate + "4", N-1);
      decimalStrings(slate + "5", N-1);
      decimalStrings(slate + "6", N-1);
      decimalStrings(slate + "7", N-1);
      decimalStrings(slate + "8", N-1);
      decimalStrings(slate + "9", N-1);  
   }
}

int main() {
  string slate = "";
  int N = 3;
  decimalStrings(slate,N);
  return 0;
}

Better Approach:

#include <iostream>

using namespace std;

void decimalStrings(string slate, int N) {
  if(n == 0)
    cout << slate << endl;
   else {
      for(char s = '0'; s <= '9'; s++)  
        decimalStrings(slate + "0", N-1); 
   }
}

int main() {
  string slate = "";
  int N = 3;
  decimalStrings(slate,N);
  return 0;
}
