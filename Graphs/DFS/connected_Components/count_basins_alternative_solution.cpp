/*Solution explanation: 
This approach will be a greedy one. If we analyze the matrix closely we can easily see that the cell with the lowest altitude in the entire matrix will always be a sink, also, that all the neighbors of the cell with the lowest altitude, will flow into that cell.



We can use this fact to systematically map which cells belong to which basin.



Create a new matrix and initialize all cells with -1.



Now iterate over the cells from lowest to highest altitude.

If the current cell is unmarked, mark it with a new id.

Mark all its unmarked neighbor to be the same as the current cell. 



Finally, count all the total number of times each id occurs in the new matrix and return in descending order.



For example:



1 5 2

2 4 7

3 6 9



Create the id matrix as 

-1 -1 -1

-1 -1 -1

-1 -1 -1



Start with the lowest altitude that is 1 at (0, 0) and mark it with a new id, and change all it’s neighbors to its id.

 0  0 -1

 0 -1 -1

-1 -1 -1



Now the next lowest ids are at (0, 2) and (1, 0)



At (0, 2), as it is unmarked mark it with a new id, skip the neighbor already marked and change the remaining

 0  0 1

 0 -1  1

-1 -1 -1



Similarly for (1, 0), as it is already marked, change its neighbors to be the same as it.

 0  0 1

 0  0 1

 0 -1 -1



Continue this until all cells have been processed. And the resultant matrix will be:



0 0 1

0 0 1

0 0 0

We can use the map to map heights to cells, and then sort the heights in ascending order to mark the cells. For a better understanding look at the code.

*/

//-------------------------------------START---------------------------------------
void count_sort(vector <int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        count[arr[i]-min]++;
    }

    for(int i = 1; i < count.size(); i++) {
        count[i] += count[i-1];
    }

    for(int i = arr.size()-1; i >= 0; i--) {
        output[ count[arr[i]-min] -1 ] = arr[i];
        count[arr[i]-min]--;
    }

    for(int i=0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

vector<int> find_basins(vector< vector<int> > matrix) {
    int row_count = matrix.size();
    int col_count = matrix[0].size();

    // To maintain ids of each element of matrix
    vector< vector<int> > basins(row_count, vector<int>(col_count, -1));

    // To store sorted entries with key as height and value as list of pair with that height
    map< int, vector< pair<int, int> > > heights;

    for (int i = 0; i < row_count; i++){
        for (int j = 0; j < col_count; j++){
            heights[matrix[i][j]].push_back(make_pair(i, j));
        }
    }

    int basin_index = 0;

    for (auto height_pair : heights) {
        for (pair<int, int> index : height_pair.second) {
            int row = index.first;
            int col = index.second;

            // If element is sink itself
            if (basins[row][col] == -1){
                basins[row][col] = basin_index++;
            }
            // Check element which is at left
            if (col > 0 && basins[row][col - 1] == -1){
                basins[row][col - 1] = basins[row][col];
            }
            // Check element which is at up
            if (row > 0 && basins[row - 1][col] == -1){
                basins[row - 1][col] = basins[row][col];
            }
            // Check element which is at down
            if (row < matrix.size() - 1 && basins[row + 1][col] == -1){
                basins[row + 1][col] = basins[row][col];
            }
            // Check element which is at right
            if (col < matrix[0].size() - 1 && basins[row][col + 1] == -1){
                basins[row][col + 1] = basins[row][col];
            }
        }
    }

    vector<int> basin_sizes(basin_index);

    for (int i = 0; i < row_count; i++){
        for (int j = 0; j < col_count; j++){
            basin_sizes[basins[i][j]]++;
        }
    }

    // Sorting by size of sinks
    count_sort(basin_sizes);

    return basin_sizes;
}
