/*Print Matrix In Spiral Order
Given a character matrix, return all the characters in the clockwise spiral order starting from the top-left.



Example

Input:

[

['X' 'Y' 'A'] 

['M' 'B' 'C']

['P' 'Q' 'R']

]
Output: "XYACRQPMB" 
For the given matrix rows = 3 and cols = 3. Spiral order is 'X' -> 'Y' -> 'A' -> 'C' -> 'R' -> 'Q' -> 'P' -> 'M' -> 'B'. So return string "XYACRQPMB" of length rows * cols = 9.
*/

//Solution:

string printSpirally(vector < vector < char > > matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int rs = 0, re = r-1;
        int cs = 0, ce = c-1;
        
        int count = 0;
        string result;
        
        while(count < r*c) {
            for(int i = cs; count < r*c && i <= ce; ++i) {
                result.push_back(matrix[rs][i]);
                ++count;
            }
            for(int i = rs+1; count < r*c && i <= re; ++i) {
                result.push_back(matrix[i][ce]);
                ++count;
            }
            for(int i = ce-1; count < r*c && i >= cs; --i) {
                result.push_back(matrix[re][i]);
                ++count;
            }
            for(int i = re-1; count < r*c && i >= rs+1; --i) {
                result.push_back(matrix[i][cs]);
                ++count;
            }
            rs += 1;
            cs += 1;
            re -= 1;
            ce -= 1;
        }
        return result;
}

