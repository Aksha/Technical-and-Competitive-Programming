triplebyte stuff:

#include <iostream>
#include <vector>
using namespace std;

class SpreadSheet{
public:
    int row;
    int column;
    vector<vector<string>> grid;

    //SpreadSheet(int r, int c) : row(r), column(c) {}
    SpreadSheet(int r, int c) {
        row = r;
        column = c;
    }

    void setData(vector<vector<string>> inp) {
        grid = inp;
    }

    vector<vector<string>> getData() {
        return grid;
    }

    void printData() {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(j == 0 && grid[i][j] != " ")  {
                    cout << grid[i][j];
                }
                else if (grid[i][j] != " "){
                    cout << "|" << grid[i][j];
                }
            }
            cout << endl;
        }
    }

    void prettyPrintData() {
        for(int i = 0; i < row; i++) {
            string temp = "";
            for(int j = 0; j < column; j++) {
                if( j == column-1 && grid[i][j] != " ") {
                    temp += " " + grid[i][j];
                }
                else if (grid[i][j] != " "){
                    temp += grid[i][j] + " | ";
                }
            }
            cout << temp << endl;
        }
    }
};


int main() {
    SpreadSheet s(4,3);
    //vector <vector <string>> inp(4,vector<string>(3));

    vector <vector <string>> inp(4,vector<string>(3));
    /*
       vector <vector <string>> inp(4,vector<string>(3, " "));
       inp[0][0] = "Bob";
       inp[0][1] = "10";
       inp[0][2] = "foo";
       inp[1][0] = "Alice";
       inp[1][1] = "5";
    */
    inp = {{"Bob","10","foo"},{"Alice","5", " "}, {" "," ", " "}, {" "," ", " "}};
    s.setData(inp);

    s.printData();
    s.prettyPrintData();
    return 0;
}
