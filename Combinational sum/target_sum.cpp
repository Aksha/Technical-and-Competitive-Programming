#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

//all combinations
void banknotes_combination(vector<int> arr, int target, vector<vector<int>> &combinations, vector<int> curr_combinations) {
    if(target == 0) {
        combinations.push_back(curr_combinations);
        return;
    }
    else if(target < 0) {
        return;
    }
    else {
        for(int j = 0; j < arr.size() && target - arr[j] >= 0; j++) {
            curr_combinations.push_back(arr[j]);
            banknotes_combination(arr,target - arr[j],combinations, curr_combinations);
            curr_combinations.pop_back();
        }
    }
    return;
}


// To execute C++, please define "int main()"
int main() {
    vector<int> arr = {10,5,1};
    int item_price = 52;
    int paid = 100;
    int target = paid - item_price;
    vector<vector<int>> combinations;
    int position = 0;
    vector<int> curr_combination;
    banknotes_combination(arr, target, combinations, curr_combination);

    int minimum = INT_MAX;
    vector<int> result_arr;
    
    //minimum combination
    for(int i = 0; i < combinations.size(); i++) {
        if(minimum > combinations[i].size()) {
            minimum = combinations[i].size();
            result_arr = combinations[i];
        }
    }
    
    //display
    unordered_map<int,int> umap;
    for(int i = 0; i < result_arr.size(); i++) {
        if(umap.find(result_arr[i]) == umap.end()) {
            umap.insert(make_pair(result_arr[i],1));
        }
        else {
            umap[result_arr[i]]++;
        }
    }


    for(unordered_map<int,int>::iterator it = umap.begin(); it != umap.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}


/*

            16
          10 5 1
        (6) (11)(15)
    10 5 1
       (1) (5)

Your previous Ruby content is preserved below:

# Problem, given an array of allowed_banknotes, define a method that computes the change in the most efficient way.

@allowed_banknotes = [10, 5, 1]

def compute_change(item_price, paid)
  # ...
  # your code
  # ...
end

# Correct Output Examples ----------------------------

# @allowed_banknotes = [10, 5, 1]
# item_price = 74
# paid =  100
# compute_change(item_price, paid)

# Correct output example (as a hash, dictionary, etc)
# {"10" => 1, "5"=> 1, "1"=> 1}

# Incorrect output example ----------------------------
# {"10" => 0, "5"=> 0, "1"=> 16}


 */
