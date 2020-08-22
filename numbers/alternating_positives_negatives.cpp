//Alternating positives and negatives
vector<int> alternating_positives_and_negatives(vector<int> array) {
    vector<int> positive;
    vector<int> negative;
    int size = array.size();
    for(int i = 0; i < size; i++) {
        if(array[i] >= 0) {
            positive.push_back(array[i]);
        }
        else {
            negative.push_back(array[i+1]);
        }
    }
    int i = 0;
    int j = 0;
    int m = positive.size();
    int n = negative.size();
    vector<int> result;
    while(i < m && j < n){ 
        result.push_back(positive[i]);
        result.push_back(negative[j]);
    }
    while(i < m) {
        result.push_back(positive[i]);
    }
    while(j < n) {
        result.push_back(negative[j]);
    }
    return result;
}

