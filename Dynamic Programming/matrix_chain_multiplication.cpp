/*

Matrix Chain Multiplication
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

(ABC)D = (AB)(CD) = A(BCD) = ....

However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations 

A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

Clearly, the first parenthesization requires less number of operations.

Given an array mtxSizes[], which represents the chain of matrices such that the i-th matrix Ai is of dimension mtxSizes[i-1] x mtxSizes[i], we need to write a function that should return the minimum number of multiplications needed to multiply the chain. Length of the chain of matrices is n and thus the size of mtxSizes is (n+1).
Example

Input: [10, 30, 5, 60]

Output: 4500
Notes

Input Format: You will be given an integer array mtxSizes.
Output: Return an integer minOps, denoting the minimum number of operations needed.
*/

//Solution: 

#include <iostream>
#include <vector>

using namespace std;

int minMultiplicationCost_helper(vector < int > mtxSizes, int n) {
    vector<vector<int>> T(n,vector<int>(n,0));
    for(int i = 0; i < n; i++)
        T[i][i] = 0;
    int minimum = 0;
    for(int l = 2; l < n; l++) {
        for(int i = 0; i < n-l; i++) {
            int j = i + l;
            T[i][j] = INT_MAX;
            for(int k = i+1; k < j; k++) {
                minimum = T[i][k] + T[k][j] + mtxSizes[i] * mtxSizes[k] * mtxSizes[j];
                if(minimum  < T[i][j])
                    T[i][j] = minimum;
            }
        }
    }
    return T[0][n-1];
}

int minMultiplicationCost(vector <int> mtxSizes) {
    vector<pair<int,int>> val;
    int n = mtxSizes.size();
    if(n == 0 || n == 1)
        return 1;
    int result = minMultiplicationCost_helper(mtxSizes,n);
    return result;
}

int main() {
    vector<int> mtxSizes = {10,30,5,60};
    int result = minMultiplicationCost(mtxSizes);
    cout << " result is : " << result << endl;
    return 0;
}
