class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int len = nums.size();
        if(len <= 1){return len;}
        
        vector<int> dp(len, 1);
        int result = 1;
        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            
            result = max(result, dp[i]);
        }
        
        return result;
    }
};
