void merge(vector<int> &arr, int start1, int end1, int start2, int end2) {
    vector<int> temp(arr.size());
    int i = start1, k = start1, j = start2; //choosing variable names signal error array out of bound exception
    while(i <= end1 && j <= end2) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else if(arr[i] > arr[j]) //run input through the code
            temp[k++] = arr[j++];
    }
    while(i <= end1)
        temp[k++] = arr[i++];
    while(j <= end2)
        temp[k++] = arr[j++];
    for(int l = start1; l <= end2; l++)
        arr[l] = temp[l];
}

void merge_sort_helper(vector<int> &arr, int start, int end) {
    if(start < end) {
        int mid = start + (end-start)/2;
        merge_sort_helper(arr,start,mid);
        merge_sort_helper(arr,mid+1,end);
        merge(arr,start,mid,mid+1,end);
    }
    return;
}

vector<int> merge_sort(vector<int> &arr) {
    merge_sort_helper(arr,0,arr.size()-1);
    return arr;
}
