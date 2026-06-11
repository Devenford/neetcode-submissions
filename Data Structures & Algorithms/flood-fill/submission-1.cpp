class Solution {
    int rows, cols;

    void dfs(vector<vector<int>>& image, int r, int c, int color, int startcolor) {
        if(r<0 || c<0 || r==rows || c==cols || image[r][c]!=startcolor || image[r][c]==color) {
            return;
        }

        image[r][c] = color;
        dfs(image, r+1, c, color, startcolor);
        dfs(image, r-1, c, color, startcolor);
        dfs(image, r, c+1, color, startcolor);
        dfs(image, r, c-1, color, startcolor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        rows = image.size();
        cols = image[0].size();
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};