#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0, length = 0;
        unordered_set<char> hashset;

        for(int R = 0; R<s.size(); R++) {
            if (hashset.count(s[R])) {
                while(s[L]!=s[R]) {
                    hashset.erase(s[L]);
                    L++;
                }
                hashset.erase(s[L]);
                L++;
            }
            hashset.insert(s[R]);
            length = max(length, R-L+1);
        }

        return length;
    }
};
