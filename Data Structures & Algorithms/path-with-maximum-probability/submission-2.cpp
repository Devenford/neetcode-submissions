#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int,double>>> adjlist;
        for (int i=0; i<edges.size(); i++) {
            // since the edges are undirected, add both directions
            adjlist[edges[i][0]].push_back(pair<int,double> {edges[i][1], succProb[i]});
            adjlist[edges[i][1]].push_back(pair<int,double> {edges[i][0], succProb[i]});
        }

        priority_queue<pair<double,int>> maxHeap;
        unordered_map<int, double> highestProbs;
        maxHeap.push(pair<double,int> {1, start_node});
        while(!maxHeap.empty()) {
            pair<double,int> p = maxHeap.top();
            maxHeap.pop();
            double w1 = p.first;
            int v1 = p.second;

            if (v1 == end_node) {
                return w1;
            }

            if (highestProbs.count(v1) > 0) {
                continue;
            }
            highestProbs[v1] = w1;

            for (pair<int,double> &p : adjlist[v1]) {
                int v2 = p.first;
                double w2 = p.second;
                if (highestProbs.count(v2) == 0) {
                    maxHeap.push(pair<double,int> {w1 * w2, v2});
                }
            }
        }

        return 0;
    }
};