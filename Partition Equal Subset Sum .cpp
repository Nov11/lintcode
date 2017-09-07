class Solution {
public:
    /*
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        // write your code here
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2){return false;}
        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;
        for(auto item : nums){
            for(int i = target; i >= item; i--){
                dp[i] = dp[i] || dp[i - item];
            }
        }
        
        return dp[target];
    }
};