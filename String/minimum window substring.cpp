/*Example One

Input:
s = AYZABOBECODXBANC
t = ABC
Output: BANC
*/


The minimum window is "BANC", which contains all letters - A B and C. We cannot find a window of smaller length than “BANC”.

string minimum_window(string S, string T) {
    string result;
    if(S.empty() || T.empty()){
        return "-1";
    }
    unordered_map<char, int> map;
    unordered_map<char, int> window;
    for(int i = 0; i < T.length(); i++){
        map[T[i]]++;
    }
    int minLength = INT_MAX;
    int letterCounter = 0;
    int slow = 0;
    int fast = 0;
    for(int k = 0; k < S.length(); k++){
        char c = S[k];
        if(map.find(c) != map.end()){
            window[c]++;
            if(window[c] <= map[c]){
                letterCounter++;
            }
        }
        if(letterCounter >= T.length()){
            while(map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]]) {//order of the commands matter here
                window[S[slow]]--;
                slow++;
            }
            if(fast - slow + 1 < minLength){
                minLength = fast - slow + 1;
                result = S.substr(slow, minLength);
            }
        }
        fast++;
    }
   if(minLength == INT_MAX) {
       return "-1";
   }
   return result;
}

