#include<vector>
using namespace std;

class NumMatrix {
    vector<vector<int>> prefixSum;  // row-wise
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            int sum = 0;
            vector<int> temp;
            for(int j = 0; j<matrix[0].size(); j++) {
                sum += matrix[i][j];
                temp.push_back(sum);
            }
            prefixSum.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int regionSum = 0;
        for (int row = row1; row<=row2; row++) {
            if (col1 == 0) {
                regionSum += prefixSum[row][col2];
            }
            else {
                regionSum += prefixSum[row][col2] - prefixSum[row][col1-1];
            }
        }
        return regionSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */