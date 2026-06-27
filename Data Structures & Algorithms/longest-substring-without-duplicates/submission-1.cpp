#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0, length = 0;
        unordered_set<char> hashset;

        for(int R = 0; R<s.size(); R++) {
            while (hashset.find(s[R]) != hashset.end()) {
                hashset.erase(s[L]);
                L++;
            }
            hashset.insert(s[R]);
            length = max(length, R-L+1);
        }

        return length;
    }
};
