// Using a monotonically decreasing stack
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> s; // stores index positions
        s.push(0);
        for(int i=1; i<temperatures.size(); i++) {
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }

        // final while loop to handle remaining elements is redundant, since the vector/array is already initialized with 0s
        // while(!s.empty()) {
        //     result[s.top()] = 0;
        //     s.pop();
        // }

        return result;
    }
};
