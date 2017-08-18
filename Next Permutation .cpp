class Solution {
    void next(vector<int>& nums){
        if(nums.size() <= 1){return;}
        int len = nums.size();
        int i = len - 1;
        for(; i - 1 >= 0; i--){
            if(nums[i] > nums[i - 1])break;
        }
        if(i == 0){reverse(nums.begin(), nums.end()); return;}
        
        int j = len - 1;
        for(; j > i - 1; j--){
            if(nums[j] > nums[i - 1])break;
        }
        
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        next(nums);
        return nums;
    }
};