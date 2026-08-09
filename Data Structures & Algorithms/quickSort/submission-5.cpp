// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
    void quickSortHelper(vector<Pair> &pairs, int s, int e) {
        if (e-s < 1) {
            return;
        }
        int pivot = pairs[e].key;
        int k = s;

        for(int i = s; i < e; i++) {
            if (pairs[i].key < pivot) {
                swap(pairs[i], pairs[k++]);
            }
        }

        swap(pairs[e], pairs[k]);
        quickSortHelper(pairs, s, k-1);
        quickSortHelper(pairs, k+1, e);
    }

public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size() -1);
        return pairs;
    }
};
