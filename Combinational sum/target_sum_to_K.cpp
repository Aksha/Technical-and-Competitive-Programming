/*
Possible To Achieve Target Sum?
Given a set of integers and a target value k, find a non-empty subset that sums up to k.

Example One
Input: [2 4 8], k = 6
Output: True
Because 2+4=6

Example Two
Input: [2 4 6], k = 5
Output: False
Because no subset of numbers from the input sums up to 5.
*/
#include <iostream>
#include <vector>

using namespace std;

void check_if_sum_possible_helper (vector <long long int> arr, long long int sum, long long int index, bool& flag) {
    if(sum < 0)
        return;
    else if (sum == 0) {
        flag = true;
        return;
    }
    else {
        while(index < arr.size() && sum - arr[index] >= 0) {
            check_if_sum_possible_helper(arr,sum-arr[index],index,flag);
            if(flag)
                return;
            else
                index++;
        }
    }
    return;
}

bool check_if_sum_possible(vector <long long int> arr, long long int k) {
    if(arr.size() == 0)
        return false;
    if(arr.size() == 1) {
        if(arr[0] == k)
            return true;
        else
            return false;
    }
    bool flag = false;
    int i = 0;
    check_if_sum_possible_helper(arr,k,i,flag);
    return flag;
}



int main() {
    vector<long long int> arr = {2,4,8};
    long long int k = 14;
    bool result = check_if_sum_possible(arr,k);
    cout << " result is " << result << endl;
    return 0;
}

//Covering edge case where K = 0;

void check_if_sum_possible_helper (vector <long long int> arr,long long int k, long long int sum, long long int index, bool& flag) {
    if(sum > k)
        return;
    else if (sum == k) {
        flag = true;
        return;
    }
    else {
        while(index < arr.size() && sum + arr[index] <= k) {
            check_if_sum_possible_helper(arr,k,sum+arr[index],index,flag);
            if(flag)
                return;
            else
                index++;
        }
    }
    return;
}

bool check_if_sum_possible(vector <long long int> arr, long long int k) {
    if(arr.size() == 0)
        return false;
    if(arr.size() == 1) {
        if(arr[0] == k)
            return true;
        else
            return false;
    }
    bool flag = false;
    int i = 0;
    long long int sum = 0;
    check_if_sum_possible_helper(arr,k,sum,i,flag);
    return flag;
}

//Improving speed: Return true as soon as 1 combination is found and not wasting iterations on future operations
void is_subSet_sum(vector<long long int> &arr, int i, bool &check, long long int sum_so_far, long long int k, bool &is_element_used){
    if(sum_so_far == k && is_element_used == true){
        check = true;
        return;
    }
    if(i == arr.size()){
        return;
    }
    is_element_used = false;
    is_subSet_sum(arr, i+1, check, sum_so_far, k, is_element_used);
    is_element_used = true;
    is_subSet_sum(arr, i+1, check, sum_so_far + arr[i], k, is_element_used);
} 
bool check_if_sum_possible(vector <long long int> &arr, long long int k) {
    bool check = false;
    bool is_element_used = false;
    is_subSet_sum(arr, 0, check, 0, k, is_element_used );
    return check;
}
