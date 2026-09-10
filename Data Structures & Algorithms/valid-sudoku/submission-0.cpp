#include<unordered_set>
#include<vector>
#include<cctype>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<unordered_set<char>>> boxes (3, vector<unordered_set<char>> (3));
        unordered_set<char> row;
        vector<unordered_set<char>> cols(9);

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                char ele = board[r][c];
                if (ele == '.') {
                    continue;
                }
                if (boxes[r/3][c/3].count(ele) || cols[c].count(ele) || row.count(ele)) {
                    return false;
                }
                boxes[r/3][c/3].insert(ele);
                cols[c].insert(ele);
                row.insert(ele);
            }
            row.clear();
        }

        return true;
    }
};
