#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache {
    list<int> order;  //LRU order
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    // <key, <value, iterator_to_pos_in_list>>
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
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        }
        else if (cache.size() == capacity) {
            cache.erase(order.front());
            order.pop_front();
        }

        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
