class Solution {
public:
    /*
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here
        int len = nums.size();
        if(len == 0){return 1;}
        vector<int> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < len; j++){
                if(nums[j] <= i){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp.back();
    }
};