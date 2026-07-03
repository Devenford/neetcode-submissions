#include<vector>
using namespace std;

/* Ex: matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
*/

class NumMatrix {
    vector<vector<int>> sumMat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        sumMat = vector<vector<int>> (rows+1, vector<int>(cols+1, 0));
        // zero-padded row and column at the beginning of sumMat

        for(int r = 0; r<rows; r++) {
            int prefixSum = 0;
            for(int c = 0; c<cols; c++) {
                prefixSum += matrix[r][c];
                int above = sumMat[r][c+1];
                sumMat[r+1][c+1] = prefixSum + above;
            }
        }

        /*Ex: sumMat = {
                { 0,  0,  0,  0,  0,  0},
                { 0,  3,  3,  4,  8, 10},
                { 0,  8, 14, 18, 24, 27},
                { 0,  9, 17, 21, 28, 36},
                { 0, 13, 22, 26, 34, 49},
                { 0, 14, 23, 30, 38, 58}
            };
        */
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++; // due to the zero-padding of sumMat
        int bottomRight = sumMat[row2][col2];
        int topRight = sumMat[row1-1][col2];
        int bottomLeft = sumMat[row2][col1-1];
        int topLeft = sumMat[row1-1][col1-1];
        return bottomRight - topRight - bottomLeft + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */