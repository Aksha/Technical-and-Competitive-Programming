#include <iostream>
#include <vector>
#include <string>

using namespace std;

void LCP(string s, int index, string temp, vector<string>& result) {
    if(index == s.size()) {
        result.push_back(temp);
        temp = "";
        return;
    }
    if((int)s[index] >= 97) {
        char c = toupper(s[index]);
        LCP(s, index + 1, temp + c, result);
    }
    LCP(s,index+1,temp+s[index],result);
    return;
}

int main() {
    string s = "a1b2";
    //output  ={a1b2,A1b2,a1B2,A1B2};
    vector<string> result;
    string temp = "";
    int i = 0;
    LCP(s,i,temp,result);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
