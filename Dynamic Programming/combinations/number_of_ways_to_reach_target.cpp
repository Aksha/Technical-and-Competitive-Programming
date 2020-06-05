//Recursive solution: time complexity: O(branching factor ^ height) 
//If m is the number of elements in the input and n is the target, it is m^n. For example, in this problem it is 3^5.


#include <iostream>
#include <vector>

using namespace std;

void combinations(vector<int> &arr, int target, int i, int &count, int sum) { // arr,5,1,0,7
    //3 cases:
    if( sum == target) {
        count++; //count = 1
        return;
    }
    else if (sum > target) {
        return;
    }
    else {
        for(int j = 0; j < arr.size() && sum + arr[j] <= target; j++) { //i= 1, sum = 0, sum + arr[i] = 3 //replace with a for loop that goes over all elements
            combinations(arr,target,i,count,sum+arr[j]); //
            i++;
        }
    }
    return;
}

int main() {
    vector<int> arr = {2,3,7};
    int target = 5;
    int i = 0;
    int count = 0;
    int sum = 0;
    combinations(arr,target,i,count,sum);
    cout << "the total combinations or ways to reach target : " << count << endl;
    return 0;
}

//Now, Dynamic programming approach: counting problems and optimation problems can be solved using DP (top down).
//Time complexity is O(m*n) where m is the target and n is the number of elements in the input. This can be better or worse than
// recursion depending on the values of m and n but stack overhead is not there and at the system level,
//iteration is faster.
#include <iostream>
#include <vector>

using namespace std;

int count_combinations(vector<int> arr, int target) {
    int size = arr.size();
    vector<int> count(size+1, 0);
    count[0] = 1; // base case
    for(int i = 0; i <= target; i++) {
        for(int j = 0; j < size; j++) {
            if(i >= arr[j]) {
                count[i] += count[i-arr[j]];
            }
        }
    }
    return count[target];
}

int main() {
    vector<int> arr = {2,3,7};
    int target = 5;
    int result = count_combinations(arr,target);
    cout << "the total number of ways : " << result << endl;
    return 0;
}
