#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(int i=0; i<s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        int matches = 0; // number of frequencies that match in freq1 and freq2
        for(int i=0; i<26; i++) {
            if (freq1[i] == freq2[i]) {
                matches++;
            }
        }

        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++)  {
            if (matches == 26) {
                return true;
            }

            // sliding window:  prevChar .... currChar
            // window size = s1.size()
            int currChar = s2[r] - 'a';
            freq2[currChar]++;
            if (freq2[currChar] == freq1[currChar]) {
                matches++;
            }
            else if (freq2[currChar] == freq1[currChar] + 1) {
                matches--;
            }

            int prevChar = s2[l] - 'a';
            freq2[prevChar]--;
            if (freq2[prevChar] == freq1[prevChar]) {
                matches++;
            }
            else if (freq2[prevChar] + 1 == freq1[prevChar]){
                matches--;
            }

            l++;
        }

        return matches == 26;
    }
};
