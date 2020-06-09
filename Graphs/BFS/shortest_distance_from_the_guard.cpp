/*
Shortest Distance From the Guard



You are given a two-dimensional character grid of size n * m. Each element of the grid is either a GUARD, an OPEN space or a WALL. Every guard can move up, down, left and right in the open space. They cannot move on the wall.

Find, for every cell, the distance from the nearest guard cell. Consider -1 as this distance for wall cells and unreachable cells.



Example One

Input:

5

5

OOOOG

OWWOO

OOOWO

GWWWO

OOOOG



Output:

3 3 2 1 0 

2 -1 -1 2 1 

1 2 3 -1 2 

0 -1 -1 -1 1 

1 2 2 1 0 



All the walls are -1. All other cells have the minimum distance to a Guard.



Example Two

Input:

1

5

GWOWG



Output: 0 -1 -1 -1 0



Open space in the middle is unreachable for the guards hence they have value -1.



Notes

Input Parameters: The function has one parameter, an array of n strings. Each string is m characters long, together they represent the grid. Strings will consist of three different characters: ‘G’ for guard, ‘O’ for open space, and ‘W’ for wall.



Output: Return a two-dimensional array of integers of size n * m. Numbers in the array must represent the distance from the corresponding cell to the nearest guard. Wall cells and cells from which a guard cannot be reached must have value -1.



Constraints:

1 <= n, m <= 10^3

*/

//Solution:

/*
 * Complete the 'find_shortest_distance_from_a_guard' function below.
 *
 * The function accepts the 2D CHARACTER ARRAY.
 * Returns 2D INTEGER ARRAY.
 */
/*vector<vector<int>> find_shortest_distance_from_a_guard(vector<vector<char>> grid) {

case 1 : if(cellNum == G) cellNum = 0;
case 2 : else if (cellNum == W) cellNum = -1;
case 3 : else computeVal //for cellNum == O
computeVal(matrix, row, col) {
    int count = 0; 
    boundary check
} (m*n)*(m*n)
Better approach: Start from 'G' and find the values. Stop when you encounter another G or your current count > existing count in that cell (G * (m*n)) {BFS}
Best Approach : Put all the Gs in the queue and apply BFS.

} */

struct GaurdNode
{
	int x;
	int y;
	int distance;
};

bool isValid(vector<vector<char>>& grid, int i, int j)
{
	return (i >= 0 && i < grid.size()) && (j >= 0 && j < grid[0].size());
}

bool isSafe(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& result)
{
	return grid[i][j] == 'O' && result[i][j] == -1;
}

void UpdateDistance(vector<vector<char>>& grid, vector<vector<int>>& result)
{
	int x, y, distance;
	GaurdNode node;
	queue<GaurdNode> Q;
	int R[] = { 0, -1, 0, 1 };
	int C[] = { -1, 0, 1, 0 };


	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 'G') {
				Q.push({i, j, 0});

				result[i].push_back(0);
				continue;
			}
			result[i].push_back(-1);
		}
	}

	while (!Q.empty()) {
		x = Q.front().x;
		y = Q.front().y;
		distance = Q.front().distance;

		Q.pop();

		for (int i = 0; i < 4; i++) {
			node.x = x + R[i], node.y = y + C[i];

			if (isValid(grid, node.x, node.y)
			&& 	isSafe(node.x, node.y, grid, result)) {
				result[node.x][node.y] = distance + 1;
				Q.push({node.x, node.y, distance + 1});
			}
		}
	}
}

vector<vector<int>> find_shortest_distance_from_a_guard(vector<vector<char>>& grid) {

	vector<vector<int> > result;

	int size =  grid.size();
	result.resize(size);
	UpdateDistance(grid, result);
	return result;
}



