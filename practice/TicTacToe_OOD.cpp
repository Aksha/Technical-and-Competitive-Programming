#include <iostream>
#include <vector>

using namespace std;


class TicTacToe {

    public:
        vector<vector<char>> grid;

        TicTacToe(vector<vector<char>>gridInput) {
             grid = gridInput;
        }
        void addToken(char input, int row, int col) {
            grid[row][col] = input;
        }
        void printBoard() {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(j == 0) {
                        cout << grid[i][j];
                    }
                    else {
                        cout << "|" << grid[i][j];
                    }
                }
                cout << endl;
            }
        }

        bool isBoardFull() {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(grid[i][j] == 'X' || grid[i][j] == '0')
                        return false;
                }
            }
            return true;
        }

};

int main(){

    vector<vector<char>> grid(3, vector<char>(3, '-'));

    char board[3][3] = {'-'};
    vector<vector<char>> board1(3,vector<char>(3));
    board[2][1] = 'o';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
         }
        cout << endl;
    }

    TicTacToe T(grid);
    T.addToken('X', 0, 1);
    T.printBoard();
    cout << "--------Next Board-----" << endl;
    TicTacToe T2(grid);
    T2.addToken('X',0,0);
    T2.printBoard();
    return 0;
}
