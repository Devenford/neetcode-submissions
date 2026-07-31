#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<cmath>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        // {<cost, v1, v2>}
        unordered_set<int> visit;
        int cost = 0;
        minHeap.push({0, 0, 0});

        while(visit.size() != points.size()) {
            vector<int> edge = minHeap.top();
            minHeap.pop();
            int w = edge[0], v1 = edge[1], v2 = edge[2];

            if (visit.count(v2) > 0) {
                continue;
            }
            visit.insert(v2);
            cost += w;

            for (int i = 0; i < points.size(); i++) {
                if (i != v2 && visit.count(i) == 0) {
                    int wt = abs(points[v2][0] - points[i][0]) + abs(points[v2][1] - points[i][1]);
                    minHeap.push({wt, v2, i});
                }
            }
        }

        return cost;
    }
};
