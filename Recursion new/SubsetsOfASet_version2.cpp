
/*
 * Complete the function below.
 */
void generate_subsets(string s, int i, vector<string> temp, vector<string> &subsets) {
    //base condition if i reaches the end of string, return;
    //copy subsets to temp.
    //for each string in temp, add s[i].
    //now iterate over temp and add to subsets;
    //now move the index position i to i+i and call the recursive function again
    if(i == s.size())
        return;
    temp = subsets;
    for(int j = 0; j < temp.size(); j++) {
        temp[j] += s[i];
        subsets.push_back(temp[j]);
    }
    temp.clear();
    generate_subsets(s,i+1, temp,subsets);
    return;
}

vector <string> generate_all_subsets(string s) {
    vector<string> temp;
    vector<string> subsets;
    subsets.push_back("");
    int i = 0;
    generate_subsets(s,i,temp,subsets);
    return subsets;
}

Result:

/*
Input: s = "abc"
Output:

a
b
ab
c
ac
bc
abc
*/
