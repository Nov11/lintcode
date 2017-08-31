class Solution {
public:
    /*
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> nums) {
        // write your code here
        int len = nums.size();
        vector<int> dpMax(len);
        vector<int> dpMin(len);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int result = nums[0];
        for(int i = 1; i < len; i++){
            if(nums[i] > 0){
                dpMax[i] = max(nums[i], nums[i] * dpMax[i - 1]);
                dpMin[i] = min(nums[i], nums[i] * dpMin[i - 1]);
            }else if(nums[i] == 0){
                dpMax[i] = 0;
                dpMin[i] = 0;
            }else{
                dpMax[i] = max(nums[i], nums[i] * dpMin[i - 1]);
                dpMin[i] = min(nums[i], nums[i] * dpMax[i - 1]);
            }
            
            result = max(result, dpMax[i]);
        }
        
        return result;
    }
};