#include<vector>
#include<utility>
using namespace std;
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
    void merge(vector<Pair> &pairs, int s, int m, int e) {
        int i = 0, j = 0, k = s; // k = s, i.e. merge in-place
        vector<Pair> left(pairs.begin() + s, pairs.begin() + m + 1); // copy
        vector<Pair> right(pairs.begin() + m + 1, pairs.begin() + e + 1); // copy

        while (i < left.size() && j < right.size()) {
            if (left[i].key <= right[j].key) {
                pairs[k++] = left[i++];
            }
            else {
                pairs[k++] = right[j++];
            }
        }

        // add remaining elements
        while (i < left.size()) {
            pairs[k++] = left[i++];
        }

        while (j < right.size()) {
            pairs[k++] = right[j++];
        }
    }
     
    void mergeSortHelper(vector<Pair> &pairs, int s, int e) {
        if (s == e) {
            return;
        }

        int m = (s+e)/2;
        mergeSortHelper(pairs, s, m);
        mergeSortHelper(pairs, m+1, e);
        merge(pairs, s, m, e);
    }

    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.empty()) {
            return {};
        }
        mergeSortHelper(pairs, 0, pairs.size()-1);
        return pairs;
    }
};
