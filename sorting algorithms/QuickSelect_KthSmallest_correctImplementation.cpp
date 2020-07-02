#include <iostream>
#include <vector>

using namespace std;

int partition(vector <int> &A, int start, int end) { //hoar's partitioning algorithm
    //int pivot = A[(start+end)/2]; 
    int left = start;
    int right = end;
    int pivot = A[start]; 
    left++; 
    while(left <= right) {
        while(A[left] < pivot) {
            left++;
        }
        while(A[right] > pivot) {
            right--;
        }
        if(left <= right) {
            swap(A[left++],A[right--]);
        }
    }
    swap(A[start], A[left]);
    return left;
}

int partition(vector<int> &arr, int start, int end) { //lomuto's partitioning algorithm
    int i = start;
    int pivot = arr[end];
    for(int j = start; j <= end-1; j++) {
        if(arr[j] <= pivot) {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

int quickSelect(vector <int> &arr, int start, int end, int k) {
    if(start <= end) {
        int pivotIndex = partition(arr, start, end);
        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex > k) {
            quickSelect(arr, start, pivotIndex - 1, k);
        } else {
            quickSelect(arr, pivotIndex+1, end, k);
        }
    }
    return arr[k];
}

int main() {
    vector <int> arr = {15, 3, 9, 8 ,5, 2, 7, 1, 6};
    int start = 0, end = arr.size()-1, k = 7;
    int result = quickSelect(arr,start, end, k-1);
    cout << "the kth smallest element is :"  << result << endl;
    return 0;
}
