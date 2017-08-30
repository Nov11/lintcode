class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++){
            for(int j = 0, k = i - 1; j < k; j++, k--){
                dp[i] += dp[j] * dp[k] * 2;
            }
            if(i % 2 == 1){
                dp[i] += dp[i / 2] * dp[i / 2];
            }
        }
        
        return dp[n];
    }
};