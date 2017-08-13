class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int result = INT_MIN;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++){
            cur = max(nums[i], nums[i] + cur);
            result = max(result, cur);
        }
        return result;
    }
};