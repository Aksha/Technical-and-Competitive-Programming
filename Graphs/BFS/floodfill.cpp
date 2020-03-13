733. Leetcode Floodfill

//Follow design patterns of C++, OOP methodologies (abstraction (interface and implementation separate), 
//encapsulation (class/struct), inheritance and polymorphism are not applicable here) and write an efficient code : 

// Solution: 

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// new color = 9
// location = (1,1)


// 11110
// 10010
// 10010
// 11100


// 11110
// 19910
// 19910
// 11100


// 0000000000000000000000
// 0000000000x00000000000
// 000000000xxx0000000000
// 00000000xxxxx000000000
// 0000000xxxxxxx00000000
// 00000000xxxxX000000000
// 000000000xxx0000000000
// 0000000000x00000000000
// 0000000000000000000000



//bucketFill()

//1. given a grid with numbers corr to colors.
//2. starting position
//3. Can be solved using BFS algorithm and DFS algorithm (To prevent call stack overhead, we prefer BFS)

class point {

    private:

        int x;
        int y;

    public:

        point() {}
        point(int r, int c) : x(r), y(c) {}

        bool isValid(vector<vector<int>> image, int oldColor, int r, int c) {
            int row = image.size();
            int col = image[0].size();

            if(r >= 0 && r < row && c >= 0 && c < col && image[r][c] == oldColor)
                return true;

            return false;
        }

        void bucketFill(vector<vector<int>> &image, int startI, int startJ, int newColor) {
            //int row = image.size();
            //int col = image[0].size();

            int oldColor = image[startI][startJ];

            if(oldColor == newColor)
                return;

            queue<point> Q;

            point root(startI,startJ);

            Q.push(root);

            while(!Q.empty()) {
                point p = Q.front();
                Q.pop();
                image[p.x][p.y] = newColor;
                vector <int> dx{-1,+1,0,0};
                vector <int> dy{0,0,-1,+1};
                for(int i = 0; i < 4; i++) {
                    if(isValid(image,oldColor, p.x+dx[i], p.y+dy[i])) {
                        Q.push(point(p.x+dx[i],p.y+dy[i]));
                    }
                }
            }
        }


        void printImage(const vector<vector<int>>& image){
            cout << "Image: " << endl;
            for(const auto& row : image){
                for(const auto& element : row){
                    cout << element << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

};


int main() {
    point P;
    vector<vector<int>> image = {
        {1,1,1,1,0},
        {1,0,0,1,0},
        {1,0,0,1,0},
        {1,1,1,0,0}};
    P.printImage(image);
    P.bucketFill(image, 1,1,9);
    P.printImage(image);
  return 0;
}
