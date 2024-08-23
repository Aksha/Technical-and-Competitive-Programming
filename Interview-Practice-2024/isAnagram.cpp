class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> s_count;
        unordered_map<char,int> t_count;
        
        for(int i = 0; i < s.size(); i++){
            s_count[s[i]]++;
            t_count[t[i]]++;
        }
        
        for(auto it=s_count.begin(); it != s_count.end(); it++) {
            if(it->second != t_count[it->first]) {
                return false;
            }
        }
        return true;
    }
};
