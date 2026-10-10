// Using binary search (array)
// since, timestamps are guaranteed to be increasing for each key.
#include<vector>
#include<utility>
#include<unordered_map>
#include<string>
using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &values = m[key];
        int L = 0, R = values.size() - 1;
        string result = "";

        while (L <= R) {
            int mid = (L+R)/2;
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }

        return result;
    }
};
