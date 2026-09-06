// using a stack]
#include<stack>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> posSpeed; // position-speed
        for(int i=0; i<position.size(); i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.rbegin(), posSpeed.rend()); // sort in descending order

        stack<double> s;
        for(pair<int,int> &p : posSpeed) {
            double remTime = ((double) target - p.first) / p.second;

            if (s.empty() || remTime > s.top()) {
                s.push(remTime);
            }
        }

        return s.size();
    }
};
