#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int word_wrap(vector<string> words, int limit, int index, vector<int> cost, int initial_limit) {
    cout << "index : " << index << "; cost at current index : " << cost[index] << endl;
    if(index == words.size()-1) {
        return 0;
    }
    if(index == 0) {
        return cost[index];
    }
    int j = index;
    while(j < words.size()) {
        if(limit != initial_limit) {
            limit = limit - words[j].size()-1;
        }
        else {
            limit = limit-words[j].size();
        }
        int power = pow(limit,3);
        if(limit > 0) {
            j = j+1;
            cost[index] = power + word_wrap(words,limit,j,cost, initial_limit);
        }
        else {
            limit = initial_limit;
        }
    }
    return cost[0];
}


int main() {
    vector<string> words = {"omg", "very", "are", "awesome"};
    int limit = 10;
    vector<int> cost(words.size(),INT_MAX);
    int index = words.size() - 2;
    string s = "";
    int initial_limit = limit;
    int result = word_wrap(words,limit,index, cost,initial_limit);
    cout << "The minimum cost is : " << result << endl;
    return 0;
}

//Dynamic programming:

/*
* Complete the 'solveBalancedLineBreaks' function below.
*
* The function accepts STRING ARRAY and INTEGER as parameter.
* Return LONG.
*/

long solveBalancedLineBreaks(vector<string> words, int limit) {
    vector<long> dp(words.size(), 0);
    long cost  = 0;
    for (int i = words.size() - 2; i>=0; i--) {
        long min_val  = LONG_MAX;
        int curr_len = 0;
        for (unsigned int j = i;  j< words.size(); j++) {
            if (i!=j) {
                curr_len += 1;
            }
            curr_len += words[j].length();
            if (curr_len > limit) {
                cost = -1;
            } else {
                cost = pow((limit - curr_len),3);
            }
            if (cost >= 0) {
                cost += dp[j+1];
                if (j == words.size()-1) {
                    cost = 0;
                }
                min_val = min(min_val, cost);
            }
        }
        dp[i] = min_val;
    }
    return dp[0];
}

