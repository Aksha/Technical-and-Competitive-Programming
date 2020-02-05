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
