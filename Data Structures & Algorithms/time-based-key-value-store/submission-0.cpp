#include<unordered_map>
#include<map>
#include<vector>
#include<string>
using namespace std;

class TimeMap {
    unordered_map<string, map<int, string>> m;

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        map<int, string>::iterator it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : (--it)->second;
    }
};
