#include <iostream>

//print all binary strings of length n
/*
 * for example: n = 3; output: 000,001,010,011,100,101,110,111
 * */

using namespace std;

void bs_helper_first(string slate, int n) {
    if(n == 0)
        cout << slate << endl;
    else {
        bs_helper_first(slate + "0", n-1);
        bs_helper_first(slate + "1", n-1);
    }
}
/*
void bs_helper_second(int n){
    if(n == 0) {
        string temp = slate + "0";
        cout << temp << endl;
        string temp1  = slate + "1";
        cout << temp1 << endl;
    }
    else {
        cout << "0" << + bs_helper_second(n-1);
        cout <<
    }
}*/

int main() {
    bs_helper_first("",5); //one way
    //bs_helper_second(5);
    return 0;
}
