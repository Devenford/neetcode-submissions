// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    void quickSortHelper(vector<Pair> &pairs, int s, int e) {
        if (e-s < 1) {
            return;
        }

        Pair pivot = pairs[e]; // last element is chosen as the pivot
        int k = s; // k = insert position in the original pairs array
        
        for(int i=s; i<e; i++) { // i<e since the last element is the pivot
            if (pairs[i].key < pivot.key) {
                swap(pairs[i], pairs[k++]);
            }
        }

        swap(pairs[e], pairs[k]);
        // pairs[e] = pivot
        // insert pivot element into its correct position, i.e. between its left and right halves
        quickSortHelper(pairs, s, k-1);
        quickSortHelper(pairs, k + 1, e); // pivot is at position k in the original array named pairs
    }

public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size()-1);
        return pairs;
    }
};
