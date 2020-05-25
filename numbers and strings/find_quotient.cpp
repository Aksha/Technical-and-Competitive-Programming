#include <iostream>

using namespace std;

int findQuotient(int a, int b, int quotient) {
    if(a <= 0) {
        return quotient;
    }
    a = a-b;
    if(a >= 0) {
        quotient = quotient + 1;
    }
    return findQuotient(a,b,quotient);
}

int findQuotient_iterative(int a, int b) {
    int quotient = 0;
    while(a >= 0) {
        a = a-b;
        if(a >= 0)
            quotient++;
    }
    return quotient;
}


int main() {
    //int a = 5; //   0101
    int a = 20, b = 3;
    int result = findQuotient(a,b,0);
    cout << "recursive result : " << result << endl;
    int result2 = findQuotient_iterative(a,b);
    cout << "iterative result : " << result2 << endl;
    return 0;
}
