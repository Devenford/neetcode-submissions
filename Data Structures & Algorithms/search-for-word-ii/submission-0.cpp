#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int wordPos = -1;  // -1 = not a word, wordPos is the position of the word in the words vector
};

class Solution {
    void dfs(int row, int col, TrieNode *curr, vector<vector<int>> &visit, vector<vector<char>>& board, vector<string>& words, vector<string> &solution) {
        if (row < 0 || col < 0 || row == board.size() || col == board[0].size() || visit[row][col]==1) {
            return;
        }
        if (curr->children.count(board[row][col]) == 0) {
            return;
        }
        
        curr = curr->children[board[row][col]];

        if(curr->wordPos >= 0) {
            solution.push_back(words[curr->wordPos]);
            curr->wordPos = -1; // don't add the word multiple times
        }

        visit[row][col] = 1;
        dfs(row+1, col, curr, visit, board, words, solution);
        dfs(row-1, col, curr, visit, board, words, solution);
        dfs(row, col+1, curr, visit, board, words, solution);
        dfs(row, col-1, curr, visit, board, words, solution);
        visit[row][col] = 0;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> solution;
        TrieNode *root = new TrieNode();
        for (int i=0; i<words.size(); i++) {
            TrieNode *curr = root;
            for (char c : words[i]) {
                if (curr->children.count(c) == 0) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->wordPos = i;
        }

        vector<vector<int>> visit(board.size(), vector<int>(board[0].size(), 0));  //visited
        for(int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                dfs(i, j, root, visit, board, words, solution);
            }
        }

        return solution;
    }
};
