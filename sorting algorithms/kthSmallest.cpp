#include <iostream>
#include <vector>

using namespace std;

int partition(vector <int> &A, int start, int end, int pivot) {
    while(start <= end) {
        while(A[start] < pivot) {
            start++;
        }
        while(A[end] > pivot) {
            end--;
        }
        if(start <= end) {
            swap(A[start++],A[end--]);
        }
    }
    return start;
}

int quickSelect(vector <int> &arr, int start, int end, int k) {
    cout << start << " " << end << endl;
    if(start <= end) {
        int pivot = arr[start + end / 2];
        int pivotIndex = partition(arr, start, end, pivot);
        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex > k) {
            quickSelect(arr, start, pivotIndex - 1, k);
        } else {
            quickSelect(arr, pivotIndex + 1, end, k);
        }
    }
    return arr[k];
}

int main() {
    vector <int> arr = {8, 15, 2, 14 ,5, 23, 11};
    int start = 0, end = arr.size()-1, k = 3;
    int result = quickSelect(arr,start, end, k-1);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << "the kth smallest element is :"  << result << endl;
    return 0;
}
