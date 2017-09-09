class Solution {
public:
    /**
     * @param n an integer
     * @return how much money you need to have to guarantee a win
     */
    int getMoneyAmount(int n) {
        // Write your code here
        vector<vector<int>> dp(1 + n, vector<int>(n + 1));
        // dp[1][1] = 0;
        for(int j = 2; j <= n; j++){
            // dp[j][j] = 0;
            for(int i = j - 1; i >= 1; i--){
                dp[i][j] = INT_MAX;
                for(int k = i; k <= j; k++){
                    int v;
                    if(k == i){
                        v = k + dp[i + 1][j];
                    }else if(k == j){
                        v = k + dp[i][j - 1];
                    }else{
                        v = k + max(dp[i][k - 1], dp[k + 1][j]);
                    }
                    dp[i][j] = min(dp[i][j], v);
                }
            }
        }
        
        return dp[1][n];
    }
};