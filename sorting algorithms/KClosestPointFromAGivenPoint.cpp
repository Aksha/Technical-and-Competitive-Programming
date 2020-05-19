int partition(vector<long long int> &pointsDistance, int start, int end) {
    int i = start;
    long long int pivot = pointsDistance[end];
    for(int j = start; j <= end-1; j++) {
        if(pointsDistance[j] <= pivot) {
            swap(pointsDistance[i],pointsDistance[j]);
            i++;
        }
    }
    swap(pointsDistance[i],pointsDistance[end]);
    return i;
}

long long int quickSelect(vector<long long int> &pointsDistance,int start, int end, int k) {
    if(start <= end) {
        int pivotIndex = partition(pointsDistance, start, end);
        if(pivotIndex == k) {
            return pointsDistance[pivotIndex];
        }
        else if(pivotIndex > k) {
            quickSelect(pointsDistance, start, pivotIndex-1, k);
        }
        else {
            quickSelect(pointsDistance, pivotIndex+1, end, k);
        }
    }
    return pointsDistance[k];
}

long long int distance(int x, int y, int p_x, int p_y) {
    return pow((x-p_x),2) + pow((y-p_y), 2);
}

vector<vector<int> > nearest_neighbours(int p_x, int p_y, int K, vector<vector<int> > &points) {
    vector<long long int> pointsDistance;
    for(int i = 0; i < points.size(); i++) {
        pointsDistance.push_back(distance(points[i][0],points[i][1], p_x, p_y));
        cout << "Points : " << points[i][0] << " : " << points[i][1] << " Points Distance : " << pointsDistance[i] << endl;

    }
    //apply quick select to pointsDistance
    int start = 0;
    int end = pointsDistance.size() - 1;

    long long int distanceK = quickSelect(pointsDistance,start, end, K-1);
    vector<vector<int>> temp;

    for(int i = 0; i < points.size(); i++) {
        if(distance(points[i][0], points[i][1], p_x, p_y) <= (distanceK)) {
            temp.push_back(points[i]);
        }
    }
    vector<vector<int>> kClosestPoints;
    int size = temp.size();
    if(size > K) {
        for(int i = 0; i < K; i++) {
            kClosestPoints.push_back(temp[size - 1 - i]);
            temp.pop_back();
        }
    }
    else {
        kClosestPoints = temp;
    }
    return kClosestPoints;
}
