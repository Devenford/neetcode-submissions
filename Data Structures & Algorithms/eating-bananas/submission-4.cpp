class Solution {
public:
    int check(int n, vector<int> &piles, int h) {
        int hours = 0;
        for(int i=0; i<piles.size(); i++) {
            hours += (piles[i] + n - 1)/n;
        }

        if (hours>h) {
            return 1;
        }
        else {
            return -1;
        }
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        int high = *max_element(piles.begin(), piles.end()), low = 1;
        int prev_mid = high;

        //mid = guess (minimum eating rate)

        while (low<=high) {
            int mid = (low+high)/2;

            if (check(mid, piles, h)>0) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                prev_mid = mid;
            }
        }

        return prev_mid;
    }
};
