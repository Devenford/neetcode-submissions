#include<string>
#include<vector>
using namespace std;

class Solution {
    bool dfs(int i, int j, int k, vector<vector<char>>& board, string &word, vector<vector<int>> &visit) {
        if (k == word.size()) {
            return true;
        }
        if (i >= board.size() || j >= board[0].size() || i<0 || j<0 || visit[i][j]) {
            return false;
        }
        if (board[i][j] != word[k]) {
            return false;
        }

        visit[i][j] = 1;
        bool result = dfs(i+1, j, k+1, board, word, visit) || dfs(i, j+1, k+1, board, word, visit) || dfs(i-1, j, k+1, board, word, visit) || dfs(i, j-1, k+1, board, word, visit);
        visit[i][j] = 0;
        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (dfs(i, j, 0, board, word, visit)) {
                    return true;
                }
            }
        }

        return false;
    }
};
