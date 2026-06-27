#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int L = 0, length = 0, maxFreq = 0; // length = length of longest substring
        unordered_map<char, int> freq; // frequency count hashmap for the characters in the current substring

        for(int R = 0; R < s.size(); R++) {
            freq[s[R]] += 1;
            maxFreq = max(maxFreq, freq[s[R]]);
            while ((R-L+1) - maxFreq > k) {  // R-L+1 = current substring length
                freq[s[L]] -= 1;
                L++;
            }
            length = max(length, R-L+1);
        }

        return length;
    }
};
