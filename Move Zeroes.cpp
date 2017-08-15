class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        // int j = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] != 0){nums[j] = nums[i]; j++;}
        // }
        // for(; j < nums.size(); j++){
        //     nums[j] = 0;
        // }
        
        for(int i = 0, j = 0; i < nums.size(); i++){
            if(nums[i]){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};