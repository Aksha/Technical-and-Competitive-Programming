Merge_K_sorted_arrays



Problem Statement:



This is a popular facebook problem.

Given K sorted arrays arr, of size N each, merge them into a new array res, such that res is a sorted array.


Assume N is very large compared to K. N may not even be known. The arrays could be just sorted streams, for instance, timestamp streams.



All arrays might be sorted in increasing manner or decreasing manner. Sort all of them in the manner they appear in input.



Note:

Repeats are allowed.
Negative numbers and zeros are allowed.
Assume all arrays are sorted in the same order. Preserve that sort order in output.
It is possible to find out the sort order from at least one of the arrays.


Input/Output Format For The Function:



Input Format:



There is only one argument: 2D Integer array arr.

Here, arr[i][j] denotes value at index j of ith input array, 0-based indexing. So, arr is K * N size array.



Output Format:



Return an integer array res, containing all elements from all individual input arrays combined.



Input/Output Format For The Custom Input:



Input Format:



The first line of input should contain an integer K. The second line should contain an integer N, denoting size of each input array.

In next K lines, ith line should contain N space separated integers, denoting content of ith array of K input arrays, where jth element in this ith line is nothing but arr[i][j], i.e. value at index j of ith array, 0-based indexing.  



If K = 3, N = 4 and arr = [

[1, 3, 5, 7],

            [2, 4, 6, 8],

            [0, 9, 10, 11]

], then input should be:



3

4

1 3 5 7

2 4 6 8

0 9 10 11



Output Format:



There will be (N*K) lines of output, where ith line contains an integer res[i], denoting value at index i of res.

Here, res is the result array returned by solution function.



For input K = 3, N = 4 and arr = [

[1, 3, 5, 7],

            [2, 4, 6, 8],

            [0, 9, 10, 11]

], output will be:



0

1

2

3

4

5

6

7

8

9

10

11



Constraints:

1 <= N <= 500
1 <= K <= 500
-10^6 <= arr[i][j] <= 10^6, for all valid i,j


Sample Test Case:



Sample Input:



K = 3, N =  4

arr[][] = { {1, 3, 5, 7},

           {2, 4, 6, 8},

           {0, 9, 10, 11}} ;



Sample Output:



[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]



Note:



A solution which dumps all elements from all arrays into one massive heap, and then extracts the elements one by one into a sorted output may pass, but is not acceptable. These issues should go away when we have a more nuanced backend.



Solution:
vector<int> merge(vector<int> first, vector<int> second) {
    int i = 0;
    int j = 0;
    int m = first.size();
    int n = second.size();
    vector<int> result;
    while(i < m  && j < n) {
        if(first[i] < second[j]) {
            result.push_back(first[i]);
            i++;
        }
        else if (first[i] > second[j]) {
            result.push_back(second[j]);
            j++;
        }
        else {
            result.push_back(first[i]);
            result.push_back(second[j]);
            i++;
            j++;
        }
    }
    while(i < m) {
        result.push_back(first[i]);
        i++;
    }
    while(j < n) {
        result.push_back(second[j]);
        j++;
    }
    return result;
}

vector<int> mergeInvert(vector<int> first, vector<int> second) {
    int i = 0;
    int j = 0;
    int m = first.size();
    int n = second.size();
    vector<int> result;
    while(i < m  && j < n) {
        if(first[i] > second[j]) {
            result.push_back(first[i]);
            i++;
        }
        else if (first[i] < second[j]) {
            result.push_back(second[j]);
            j++;
        }
        else {
            result.push_back(first[i]);
            result.push_back(second[j]);
            i++;
            j++;
        }
    }
    while(i < m) {
        result.push_back(first[i]);
        i++;
    }
    while(j < n) {
        result.push_back(second[j]);
        j++;
    }
    return result;
}

vector<int> mergeArraysHelper(vector<vector<int>> &arr) {
    while(arr.size() > 1) {
        vector<int> result;
        vector<int> first = arr[0];
        int m = first.size();
        vector<int> second = arr[1];
        if(first[0] <= first[m-1])
            result = merge(first,second);
        else if(first[0] > first[m-1])
            result = mergeInvert(first,second);
        arr.push_back(result);
        arr.erase(arr.begin() + 0);
        arr.erase(arr.begin() + 0);
        mergeArraysHelper(arr);
    }
    return arr.front();
}
vector<int> mergeArrays(vector<vector<int>> arr) {
    return mergeArraysHelper(arr);
}
