class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i =0; i<s.size(); i++) {
            int L = i, R = i;
            // odd length
            while (L >= 0 && R < s.size() && s[L] == s[R]) {
                count++;
                L--;
                R++;
            }

            // even length
            L = i, R = i+1;
            while (L >= 0 && R < s.size() && s[L] == s[R]) {
                count++;
                L--;
                R++;
            }
        }

        return count;
    }
};
