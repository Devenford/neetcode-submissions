#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

class Solution {
    priority_queue<vector<double>> heap; //max heap
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (vector<int> &point : points) {
            double dist = sqrt(point[0] * point[0] + point[1] * point[1]);

            if (heap.size() == k) {
                vector<double> farthest = heap.top();
                if (dist < farthest[0]) {
                    heap.pop();
                    vector<double> temp = {dist, double(point[0]), double(point[1])};
                    heap.push(temp);
                }
            }
            else {
                vector<double> temp = {dist, double(point[0]), double(point[1])};
                heap.push(temp);
            }
        }

        vector<vector<int>> kclosest;
        while (!heap.empty()) {
            vector<double> temp = heap.top();
            heap.pop();
            kclosest.push_back({int(temp[1]), int(temp[2])});
        }

        return kclosest;
    }
};
