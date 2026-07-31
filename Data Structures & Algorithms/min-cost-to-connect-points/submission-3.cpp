#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<cmath>
#include<climits>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), cost = 0, edges = 0, currNode = 0;
        vector<int> dist(n, INT_MAX); // dist[i] = min known distance from the MST (any visited node) to node i
        vector<bool> visit(n, false);

        while(edges < n-1) {
            visit[currNode] = true;
            int nextNode = -1;

            for (int i = 0; i < n; i++) {
                if (visit[i]) {
                    continue;
                }

                int currDist = abs(points[currNode][0] - points[i][0]) + abs(points[currNode][1] - points[i][1]);
                dist[i] = min(dist[i], currDist);

                if (nextNode == -1 || dist[i] < dist[nextNode]) {
                    nextNode = i;
                }
            }
            
            cost += dist[nextNode];
            currNode = nextNode;
            edges++;
        }

        return cost;
    }
};
