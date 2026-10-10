#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);

        for(char c : s1) {
            freq[c - 'a']++;
        }

        vector<int> window(26, 0);
        for(int i=0; i<s2.size(); i++) {
            if (i < s1.size()) {
                window[s2[i] - 'a']++;
                continue;
            }

            if (window == freq) {
                return true;
            }
            window[s2[i-s1.size()] - 'a']--;
            window[s2[i] - 'a']++;
        }

        return window == freq ? true : false;
    }
};
