#include <iostream>

using namespace std;

//Permutation without repetition: abc = abc,acb,bac,bca,cab,cba

void permutation(string slate, string S) {
    if(S.size() == 0)
        cout << slate << endl;
    else {
        for(int i = 0; i < S.size(); i++) {
            permutation(slate + S[i],S.substr(0,i) + S.substr(i+1));
        }
    }
}
int main() {
    string S = "abc";
    permutation("",S);
    return 0;
}
