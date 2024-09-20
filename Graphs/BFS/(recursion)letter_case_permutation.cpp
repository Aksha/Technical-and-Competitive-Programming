#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

/*9    1     1
 *| \ \ \
 * w x y z (i = 1)
 * |
 * w1 (i = 2)
 * |
 * w11 (i = 3)
 * */

void letter_case_permutation(string input, vector<string> mapping,int i, string result){
    if(i == input.size()) {
        cout << "The permutations are : " << result << endl;
        return;
    }
    int curr = input[i] - '0';
    for(int j = 0; j < mapping[curr].size(); j++) { //mapping[curr] == "wxyz"
        result += mapping[curr][j];
        letter_case_permutation(input, mapping,i+1,result);
        result.pop_back();
    }
    return;
}

int main() {
    vector<string> mapping = {"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    string result = "";
    letter_case_permutation("650",mapping,0,result);
    return 0;
}
