#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    // key, <value, iterator to key's position/node in the list order>
    list<int> order;  // stores the keys in lru order, first element/key is the least recently used
    // the last element is the recently accessed or inserted key 
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) { // key exists, so update its value
            order.erase(cache[key].second);
        }
        else if (cache.size() == capacity) { // key doesn't exist, but the cache is full
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
