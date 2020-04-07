/*
Notes

Input Parameters: Function has two arguments:

n, size of the board, and
moves, array of integers defining the snakes and ladders:
moves[i] = -1: no ladder or snake starts at i-th cell
moves[i]  < i: snake from i down to moves[i]
moves[i]  > i: ladder from i up to moves[i]
The indices and values in moves array are zero-based, for example moves[1]=18 means there is a ladder from cell 2 up to cell 19. moves for “Example One” above looks like this:

[-1, 18, -1, -1, -1, -1, -1, -1, 2, -1, -1, 15, -1, -1, -1, -1, -1, -1, -1, -1]



Output: Function must return an integer, the minimum number of dice rolls required to reach the last cell from the first. Return -1 if the last cell cannot be reached.



Constraints:

1 <= n <= 10^5
0 <=  moves[i] <= n-1
No snake starts from the last cell and no ladder starts from the first cell.
No snake or ladder starts from a cell where another snake or ladder arrives.


Custom Input 

Input Format:

First line of input contains n (number of cells on the board).

Second line also contains n (size of array moves).

Next n lines contain values from moves[0] to moves[n-1].



For n = 20 and moves = [-1, 18, -1, -1, -1, -1, -1, -1, 2, -1, -1, 15, -1, -1, -1, -1, -1, -1, -1, -1] input would be as follows:

20

20

-1

18

-1

-1

-1

-1

-1

-1

2

-1

-1

15

-1

-1

-1

-1

-1

-1

-1

-1



Output Format: The only line of output contains the return integer value, e.g.

2
*/

int minNumberOfRolls(int n, vector<int> moves) {
    int start = 0;
    vector<int>visited(n, 0);
    while(moves[start] != -1) {
        visited[start] = true;
        start = moves[start];
    }
    if(start == n-1) {
        return 0;
    }
    queue<int>q;
    q.push(start);
    int rolls = 0;
    while(!q.empty()) {
        rolls++;
        int size = q.size();
        for(int index = 0; index < size; index++) {
            int top = q.front();
            q.pop();
            for(int i = 1; i <= 6; i++) {
                int new_num = top + i;
                while (new_num <= n - 1 && moves[new_num] != -1)
                {
                    visited[new_num] = true;
                    new_num = moves[new_num];
                }
                if (new_num <= n - 1 && visited[new_num] == false)
                {
                    visited[new_num] = true;
                     if(new_num == n-1) {
                        return rolls;
                    } else {
                        q.push(new_num);
                    }
                }
            }
        }
    }
    return -1;
}

