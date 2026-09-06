#include<utility>
#include<vector>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> posSpeed; // position-speed
        for(int i=0; i<position.size(); i++) {
            posSpeed.push_back({position[i], speed[i]});
        }
        sort(posSpeed.begin(), posSpeed.end());

        float remTime = 0; // remaining time, time required to reach the target
        int fleetCount = 0;
        for(int i=position.size()-1; i>=0; --i) {
            if (posSpeed[i].first + remTime * posSpeed[i].second< target) {
                fleetCount++;
                remTime = ((float) target - posSpeed[i].first) / posSpeed[i].second;
            }
        }
        return fleetCount;
    }
};
