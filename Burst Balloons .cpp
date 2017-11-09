class Solution {
public:
    /*
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(len == 0){return 0;}
        
        vector<vector<int>> dp(len, vector<int>(len));
        
        //dp[i][j] = max(dp[i][j], nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j]) k>=i && k <=j
        //dp[i][i] = nums[i] * nums[i-1] * nums[i+1]
        
        for(int i = len - 1; i >= 0; i--){
            dp[i][i] = nums[i] * (i-1 >= 0? nums[i - 1] : 1) * (i + 1 < len ? nums[i + 1] : 1);
            for(int j = i + 1; j < len; j++){
                for(int k = i; k <= j; k++){
                    int b = i - 1 >= 0 ? nums[i - 1] : 1;
                    int e = j + 1 < len ? nums[j + 1] : 1;
                    dp[i][j] = max(dp[i][j], b * nums[k] * e + (k - 1 >= i ? dp[i][k - 1] : 0) + (k + 1 <= j ? dp[k + 1][j] : 0));
                }
            }
        }
        
        return dp[0][len - 1];
    }
};