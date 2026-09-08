#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqToAnagram;
        for(string &s : strs) {
            vector<int> freq(26, 0);
            for(char c : s) {
                freq[c - 'a']++;
            }
            string key;
            for(int f : freq) {
                key.append(to_string(f) + ',');
            }
            freqToAnagram[key].push_back(s);
        }

        vector<vector<string>> sol;
        for(pair<const string, vector<string>> &p : freqToAnagram) {
            sol.push_back(p.second);
        }

        return sol;
    }
};
