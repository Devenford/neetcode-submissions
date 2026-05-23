// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> output;
        if (pairs.empty()) {
            return output;
        }
        output.push_back(pairs);
        for(int i=1; i<pairs.size(); i++) {
            int j = i-1;
            while(j>=0 && pairs[j+1].key < pairs[j].key) {
                Pair temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
                j--;
            }
            output.push_back(pairs);
        }
        return output;
    }
};
