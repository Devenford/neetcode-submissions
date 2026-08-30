class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        vector<int> prev(M+1, 0);

        // Base Case:
        // word1[N:] is empty, so we need to insert all remaining characters of word2[j:] to convert "" into word2[j:]
        for(int j=M; j>=0; --j) {
            prev[j] = M-j;
        }
        
        // dp[i][j] represents the minimum number of operations required to convert the suffix word1[i:] into the suffix word2[j:]
        // [i:] is from index i to the end of the string
        for (int i=N-1; i>=0; --i) {
            vector<int> dp(M+1, 0);
            
            // Base Case:
            // word2[M:] is empty, so we need to delete all remaining characters of word1[i:] to convert word1[i:] into ""
            dp[M] = N - i;

            for (int j=M-1; j>=0; --j) {
                if (word1[i] == word2[j]) {
                    dp[j] = prev[j+1];
                }
                else {
                    dp[j] = 1 + min({dp[j+1], prev[j], prev[j+1]});
                }
            }
            prev = dp;
        }
        return prev[0];
    }
};
