#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        for (int i=0; i<s.size(); i++) {
            int L = i, R = i;
            // odd length
            while(L >= 0 && R < s.size() && s[L] == s[R]) {
                if (R-L+1 > longest.size()) {
                    longest = s.substr(L, R-L+1);
                }
                L--;
                R++;
            }

            // even length
            L = i, R = i+1;
            while(L >= 0 && R < s.size() && s[L] == s[R]) {
                if (R-L+1 > longest.size()) {
                    longest = s.substr(L, R-L+1);
                }
                L--;
                R++;
            }
        }
        return longest;
    }
};
