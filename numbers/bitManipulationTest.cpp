#include <iostream>
#include <string>

using namespace std;
int main() {
    int number = 131;
    string result = "";
    while(number != 0) {
        int temp = number%2;
        result += temp+'0';
        number = number/2;
    }
    reverse(result.begin(), result.end());
    cout << "the bit representation is : " << result << endl;

    string result2 = "";
    int number2 = 131;
    int result1 = 1;
    while(number2 > 1) {
        number2 = number2>>1;
        int temp  = number2&1; //0011 & 0001 = 0001..
        result1 = result1*10 + temp;
    }

    int reversedNumber = 0;
    int remainder = 0;
    while(result1 != 0)
    {
        remainder = result1%10;
        reversedNumber = reversedNumber*10 + remainder;
        result1 /= 10;
    }

    cout << "Reversed Number = " << reversedNumber;
    return 0;
}
