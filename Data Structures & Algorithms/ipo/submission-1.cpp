#include<queue>
#include<utility>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>> profitHeap;   // <int, int> = <profit, index>
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> capitalHeap;
        // <int, int> = <capital, index>
        // for a pair, sorting is performed by the first element, then the second
        int totalCapital = w;
        // capitalHeap is minHeap to choose the least expensive/capital project
        // profitHeap is a maxHeap to choose the most profitable project

        for (int i=0; i<capital.size(); i++) {
            capitalHeap.push({capital[i], i});
        }

        while(k > 0) {
            if (capitalHeap.top().first > totalCapital) {
                break; // none of the capitals are <= totalCapital (none of them meet the capital requirement)
            }

            while(!capitalHeap.empty() && capitalHeap.top().first <= totalCapital) {
                profitHeap.push({profits[capitalHeap.top().second], capitalHeap.top().second});
                capitalHeap.pop();
            }
            
            totalCapital += profitHeap.top().first;
            profitHeap.pop();
            k--;
        }

        return totalCapital;
    }
};