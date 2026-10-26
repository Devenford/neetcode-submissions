// BFS
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

// Each word is a vertex/node in a graph. One word is connected to another word only if the difference in the number of characters between the words is 1.

// Build an adjacency list based on this idea and perform BFS to find the shortest path from the beginWord to the endWord (i.e. the minimum number of words within the transformation sequence needed to obtain the endWord)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // For the adjacency list: For each word in the list (including beginWord), generate patterns by replacing each character with '*' and group words by these patterns.
        // Ex: for the word "hot" => "*ot", "h*t", "ho*"
        unordered_map<string, vector<string>> adjList;
        // <pattern, [words with that pattern]>
        wordList.push_back(beginWord);
        for (string &s : wordList) {
            for(int i=0; i<s.size(); i++) {
                adjList[s.substr(0, i) + "*" + s.substr(i+1)].push_back(s);
            }
        }

        queue<string> q;
        q.push(beginWord);
        int depth = 0; // bfs depth/level
        unordered_set<string> visit;
        visit.insert(beginWord);
        while(!q.empty()) {
            depth++;
            int qlength = q.size();
            for(int i=0; i<qlength; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return depth;
                }
                for(int j=0; j<word.size(); j++) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j+1);
                    for(string &s : adjList[pattern]) {
                        if (s != word && !visit.count(s)) {
                            q.push(s);
                            visit.insert(s);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
