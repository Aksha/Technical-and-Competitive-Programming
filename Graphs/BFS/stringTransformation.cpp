
/*
 * Complete the function below.
words = ["cat", "hat", "bad", "had"]
start = "bat"
stop = "had"
Output:

["bat", "bad", "had"]
or 
["bat", "hat", "had"]
The following solution has a time complexity of O(number of words * number of words * length of the word * 26) -- Can I do better? For larger inputs, time limit exceeded on online compilers


 */
vector<string> string_transformation(vector<string> words, string start, string stop) {

    if(start == stop && words.size() == 0)
        return {"-1"};
    vector<string> result;
    unordered_map<string,string> parent;
    unordered_set<string> hset(words.begin(), words.end());
    if(hset.find(stop) == hset.end())
        hset.insert(stop);
    queue<string> Q;
    Q.push(start);
    string final = "";
    while(!Q.empty()) {
        string curr = Q.front();
        Q.pop();
        for(int i = 0; i < curr.size(); i++) {
            string temp = curr;
            for(char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                if(hset.find(temp) != hset.end()) {
                    Q.push(temp); //Q = {bad,had}
                    parent.insert(make_pair(temp,curr)); //parent[cat] = bat; parent[hat] = bat; parent[bad] = bat; parent[had] = hat
                    hset.erase(temp); // hset = {}
                }
            }
        }
        if(curr == stop) {
            final = curr;
            break;
        }
    }
    if(final.empty())
        return {"-1"};
    while(!final.empty()) {
        result.push_back(final);
        final = parent[final];
    }
    reverse(result.begin(), result.end());
    return result;
}
