class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low=0, high = m*n-1;

        while(low<=high) {
            int mid = (low+high)/2;
            int midx = mid/n, midy = mid%n;
            if(matrix[midx][midy]<target) {
                low = mid+1;
            }
            else if (matrix[midx][midy]>target) {
                high = mid-1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
