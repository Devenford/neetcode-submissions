#include<cctype>
using namespace std;

class Solution {
    bool isAlphaNum(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }

public:
    bool isPalindrome(string s) {
        int L = 0, R = s.size()-1;
        while(L<R) {
            if(!isAlphaNum(s[L])) {
                L++;
                continue;
            }
            if(!isAlphaNum(s[R])) {
                R--;
                continue;
            }


            if (tolower(s[L]) != tolower(s[R])) {
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
};
