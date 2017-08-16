class Solution {
    void next(vector<int>& nums){
        if(nums.size() <= 1){return;}
        int i = nums.size() - 2;
        for(; i >= 0; i--){
            if(nums[i] < nums[i + 1]){break;}
        }
        if(i < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        for(; j > i; j--){
            if(nums[i] < nums[j]){break;}    
        }
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int>> result{nums};
        next(nums);
        while(result[0] != nums){
            result.push_back(nums);
            next(nums);
        }
        
        return result;
    }
};
