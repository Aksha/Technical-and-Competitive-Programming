/* 

options
 2 3 7
 0 0 0
 0 0 1
 0 1 0
 1 0 0
start at 0   
 
 
 2 + 3 = 5
 3 + 2 = 5
 
 Number of ways to achieve score of 5 = 2
 
 

222 = 6
 33 = 6
 
 Number of ways to achieve score of 6 = 2
 
 
 7
 
  7 = 7
322 = 7
232 = 7
223 = 7


2 3 7 

2,3 = 5
3,2 = 5

0 .. i

function of options and final score = number of ways of achieve that score

How do we implement that function?




      0
      
    2 3 7
   
   
 237        237      237
 4 5 9     5 6 10    9 10 14
 

3^n
    
  1. 0 is also the base case
  2. even smallest number is greater than target
  3. Don't use a DS to store values unnecessarily
  4. Improvements in the way I fig out the solution
  5. Time complexity. practice again. O(branching factor ^ height). draw the recursion tree.
  6.
    
set, target
index
various combinations = subsets.
0 ways if no subset
all positive numbers
 */

#include <iostream>

using namespace std;

void combinations(vector<int> arr, int target, int i, int &count, int sum) { // arr,5,1,0,7
    //3 cases:
    if( sum == target) {
        count++; //count = 1
        sum = 0; //sum = 0
        return;
    }
    else if (sum > target) {
        sum = sum - arr[i];
        return;
    }
    else {
        while(i < arr.size() && sum + arr[i] <= target) { //i= 1, sum = 0, sum + arr[i] = 3
            combinations(arr,target,i,count,sum+arr[i]); // 
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
    combinations(arr,target,i,&count,sum);
    cout << "the total combinations or ways to reach target : " << count << endl;
    return 0;
}
