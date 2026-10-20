#include<unordered_map>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqs, freqt;
        for(char c : t) {
            freqt[c]++;
        }

        int L = 0, solL = 0, solR = INT_MAX, have = 0, need = freqt.size();
        // need is the number of chars that must match Ex: if t = "AAB", need = 2, for 2 chars A and B
        // have is the number of frequencies that match

        for(int R = 0; R < s.size(); R++) {
            if (freqt.count(s[R])) {
                freqs[s[R]]++;
                if (freqs[s[R]] == freqt[s[R]]) {
                    have++;
                }
            }

            while (have == need) {
                if ((R - L + 1) < (solR - solL + 1)) {
                    solL = L;
                    solR = R;
                }
                if (freqt.count(s[L])) {
                    if (freqs[s[L]] == freqt[s[L]]) {
                        have--;
                    }
                    freqs[s[L]]--;
                }
                L++;
            }
        }

        return solR == INT_MAX ? "" : s.substr(solL , solR - solL + 1);
    }
}; 
