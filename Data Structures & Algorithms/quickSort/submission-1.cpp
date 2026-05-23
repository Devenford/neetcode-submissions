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
    vector<Pair> performQuickSort(vector<Pair> &pairs, int s, int e) {
        if(e-s+1<=1) {
            return pairs;
        }
        
        Pair pivot = pairs[e];
        int insertPos = s;

        for(int i=s; i<e; i++) {
            if(pairs[i].key < pivot.key) {
                Pair temp = pairs[insertPos];
                pairs[insertPos] = pairs[i];
                pairs[i] = temp;
                insertPos++;
            }
        }

        pairs[e] = pairs[insertPos];
        pairs[insertPos] = pivot;

        performQuickSort(pairs, s, insertPos-1);
        performQuickSort(pairs, insertPos+1, e);

        return pairs;
    }

    vector<Pair> quickSort(vector<Pair>& pairs) {
        if(pairs.empty()) {
            return pairs;
        }
        return performQuickSort(pairs, 0, pairs.size()-1);
    }
};
