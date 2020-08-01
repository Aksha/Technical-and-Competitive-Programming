Sliding Window Maximum

Share
Given an array nums, there is a sliding window of size k which is moving from the very left of the array
to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by 
one position. Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
/*
 * Complete the function below.
 */
 
 //this solution has linear time complexity. THe priority queue approach will take O(nlogn) as removing the
 //element out of the sliding window can happen only if the element to be removed is at the top of the heap.
 //There is also a O(nlogk) solution which is pretty straightfoward and brute force approach
vector <int> max_in_sliding_window(vector <int> arr, int k) {
    int n = arr.size();
    vector<int> result(n - k + 1);
    deque<int> dq; // Deque is storing indices, not actual elements of arr.

    for (int i = 0; i < n; i++) {
        //remove the element that is not a part of the sliding window. So check if the first element in the queue has an index that should be out of the sliding window
        if(!dq.empty() && i-k == dq.front()) {
            dq.pop_front();
        }
        //The element at the top of the deque shoud be the largest or maximum element in the current window. So store
        //the dq in the order of decreasing values of the elemnt (increasing value of indices (obviously))
        while(!dq.empty() && arr[i] >= arr[dq.front()]) {
            dq.pop_front();
        }
        //insert the current element in the deque
        dq.emplace_back(i);
        //if the current index position exceeds the size of the sliding window, the front element in deque can be stored as result
        if(i >= k-1) result.push_back(arr[dq.front()]);
    }
    return ans;
}


