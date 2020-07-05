long long MOD = 1e9 + 7;

int dp_helper(unordered_set<string> & string_hash, string & txt, long long int i) {

    long long int n = txt.size();

    vector<long long int> DP(n+1);

    DP[n] = 1;

    for(long long int i = n -1; i >= 0; --i) {
        long long int result = 0;

        string segment = "";
        
        for(long long int index = i ; index < txt.size(); ++index) {
            segment.push_back(txt[index]);
            if(string_hash.find(segment) != string_hash.end()) {
                result += DP[index+1];
                result %= MOD;
            }
        }
        
        DP[i] = result;
    }
    return DP[0];
}

int wordBreakCount(vector<string> &dictionary, string &txt)
{
    unordered_set<string> string_hash;
    long long int n = dictionary.size();

    for(long long int i = 0; i < n; ++i) {
        string_hash.insert(dictionary[i]);
    }

    return dp_helper(string_hash, txt, 0);
}



