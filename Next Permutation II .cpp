class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        int i = len - 1;
        for(; i >= 1; i--){
            if(nums[i] > nums[i - 1]){break;}
        }
        
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = len - 1;
        for(; j > i - 1; j--){
            if(nums[j] > nums[i - 1]){
                break;
            }
        }
        
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};