// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
void merge(vector<Pair> &pairs, int s, int m, int e) {
    vector<Pair> left(pairs.begin()+s, pairs.begin()+m+1), right(pairs.begin()+m+1, pairs.begin()+e+1);

    int i = 0, j = 0, k = s;
    while(i<left.size() && j<right.size()) {
        if(left[i].key <= right[j].key) {
            pairs[k++] = left[i++];
        }
        else {
            pairs[k++] = right[j++];
        }
    }

    while(i<left.size()) {
        pairs[k++] = left[i++];
    }

    while(j<right.size()) {
        pairs[k++] = right[j++];
    }
}

vector<Pair> mergesort(vector<Pair>& pairs, int s, int e) {
    if(s==e) {
        return pairs;
    }

    int m = (s+e)/2;
    mergesort(pairs, s, m);
    mergesort(pairs, m+1, e);
    merge(pairs, s, m, e);
    return pairs;
}

class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if(pairs.empty()) {
            return pairs;
        }
        return mergesort(pairs, 0, pairs.size()-1);
    }
};
