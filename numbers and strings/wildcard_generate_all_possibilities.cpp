#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the find_all_possibilities function below.
 */
void find_all_possibilities_helper(string s, int size, int index, string stringSoFar, vector<string> &result) {
    if (index == size) {
        result.push_back(stringSoFar);
        return;
    }
    if(s[index] == '?') {
        find_all_possibilities_helper(s,size,index+1,stringSoFar + "0",result);
        find_all_possibilities_helper(s,size,index+1,stringSoFar + "1",result);
    }
    else {
        find_all_possibilities_helper(s,size,index+1,stringSoFar + s[index],result);
    }
    return;
}

vector<string> find_all_possibilities(string s) {
    /*
     * logic thinking =  10 - 15 mins
       code = start time : 2 44 pm
       first version code complete : 2 51 pm only one error on char compare line 14.
       Total time 6 + 10 mins for thinking and writing = 16 mins - 21 mins. 
       
     */
    if(s.size() == 0)
        return {};
    int index = 0;
    vector<string>result;
    string stringSoFar = "";
    find_all_possibilities_helper(s,s.size(),index,stringSoFar,result);
    return result;
}


int main() {
    string s = "1?0?";
    vector<string> result = find_all_possibilities(s);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
