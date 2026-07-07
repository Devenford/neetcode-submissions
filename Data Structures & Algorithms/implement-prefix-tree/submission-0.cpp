#include<unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class PrefixTree {
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (curr->children.count(c)==0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (char c: word) {
            if (curr->children.count(c) == 0) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (char c: prefix) {
            if (curr->children.count(c) == 0) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
