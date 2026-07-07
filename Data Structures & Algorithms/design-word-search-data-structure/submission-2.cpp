#include<unordered_map>
#include<string>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
    TrieNode *root;

    bool multiSearch(string &word, TrieNode *curr, int i) {
        while (i<word.size()) {
            char c = word[i];
            if (c == '.' && curr->children.size() != 0) {
                for (char temp='a'; temp<='z'; temp++) {
                    if (curr->children.count(temp) > 0 && multiSearch(word, curr->children[temp], i+1)) {
                        return true;
                    }
                }
                return false; //none of the dfs paths match, from 'a' to 'z'
            }
            else if (curr->children.count(c) == 0) {
                return false;
            }
            curr = curr->children[c];
            i++;
        }
        return curr->word;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return multiSearch(word, root, 0);
    }
};
