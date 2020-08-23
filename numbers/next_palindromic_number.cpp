#include <iostream>
#include <string>

using namespace std;

bool is_palindrome_number(long long int n) {
    long long int palindrome = -1;
    long long int ncopy = n;

    while(ncopy  > 0) {
        long long int temp = ncopy%10;
        if(palindrome == -1) {
            palindrome = temp;
        }
        else {
            palindrome = palindrome * 10 + temp;
        }
        ncopy = ncopy/10;
    }
    if(palindrome == n) {
        return true;
    }
    return false;
}

long long int find_next_palindrome_number(long long int n) {
    n++;
    while(is_palindrome_number(n) == false) {
        n = n+1;
    }
    return n;
}
int main() {
    long long int n = 10;
    long long int result = find_next_palindrome_number(n);
    cout << result << endl;
    return 0;
}
