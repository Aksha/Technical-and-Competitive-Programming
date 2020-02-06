
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)


/*1. Calculate distance of each point from the origin and put it in a hashmap. unordered_map or store it as an array variable.
2. apply quickSelect algorithm on the calculated points.
3. Find out the kth point and it's distance.
4. Now go over the input array and check if the distance of each point is <= the kth point's distance and store it in a result variable called KClosestPoints
5. return kClosestPoints
*/

class Solution {
public:
    int partition(vector<int> &pointsDistance, int start, int end) {
        int i = start, pivot = pointsDistance[end];
        for(int j = start; j <= end-1; j++) {
            if(pointsDistance[j] <= pivot) {
                swap(pointsDistance[i],pointsDistance[j]);
                i++;
            }
        }
        swap(pointsDistance[i],pointsDistance[end]);
        return i;
    }
    
    int quickSelect(vector<int> &pointsDistance,int start, int end, int k) {
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
    
    int distance(int x, int y) {
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> pointsDistance;
        for(int i = 0; i < points.size(); i++) {
            pointsDistance[i] = distance(points[i][0],points[i][1]);
        }
        //apply quick select to pointsDistance
        int start = 0;
        int end = pointsDistance.size() - 1;
        
        int distanceK = quickSelect(pointsDistance,start, end, K-1);
        vector<vector<int>> kClosestPoints;
        for(int i = 0; i < points.size(); i++) {
            if(distance(points[i][0], points[i][1]) <= distanceK) {
                kClosestPoints.push_back(points[i]);
            }
        }
        return kClosestPoints;
    }
};
