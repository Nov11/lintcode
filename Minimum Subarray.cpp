class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int result = INT_MAX;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++){
            cur = min(cur + nums[i], nums[i]);
            result = min(result, cur);
        }
        
        return result;
    }
};
