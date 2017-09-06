class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int len = costs.size();
        if(len == 0){return 0;}
        
        vector<vector<int>> dp(len, vector<int>(3));
        dp[0] = costs[0];
        for(int i = 1; i < len; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = costs[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
            }
        }
        return min(dp[len - 1][0], min(dp[len - 1][1], dp[len - 1][2]));
    }
};