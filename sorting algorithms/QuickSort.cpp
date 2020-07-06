/*On the average quicksort has O(n log n) complexity,In worst case, quicksort runs O(n2) time and constant space (in place) */


#include <iostream>
#include <vector>

using namespace std;

//quick sort
//quick select Kth largest and smallest
//k closest points from the origin
//frog jumping problem
// left             right
// 8 15 2 14 5 23 11 4
// i       p         j
//    i    p         j
// 8 4  2 14 5 23 11 15
//      i  p      j
//         p i    j


int partition(vector <int> &A, int start, int end) { //hoare's
    //int pivot = A[(start+end)/2]; 
    int left = start;
    int pivot = A[left]; 
    start++; 
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
    swap(A[start], A[left]);
    return start;
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

void quicksort(vector<int> &A, int start, int end) {
    if(start >= end)
        return;
    int index = partition(A, start, end);
    quicksort(A, start,index-1);
    quicksort(A, index, end);
}

int main() {
    vector <int> A = {8, 15, 2, 14 ,5, 23, 11}; //sorted order: 2,4,5,8,11,14,23
    int start = 0;
    int end = A.size() - 1;
    if(end == -1) {
        cout << "array is empty" << endl;
        return 1;
    }
    if(end == 0) {
        cout << "arr has one element no sorting required" << A[0] << endl;
        return 1;
    }

    quicksort(A, start, end);
    for(int i = 0; i <= end; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}
