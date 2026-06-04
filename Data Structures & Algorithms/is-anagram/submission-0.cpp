#include<iostream>
#include<unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> countMap;

        for (char &c : s) {
            if (countMap.count(c) == 0) {
                countMap[c] = 1;
            }
            else {
                countMap[c]++;
            }
        }

        for (char &c : t) {
            if (countMap.count(c) == 0) {
                return false;
            }
            countMap[c]--;
            if(countMap[c] == 0) {
                countMap.erase(c);
            }
        }

        if (countMap.size()==0) {
            return true;
        }
        else {
            return false;
        }
    }
};
