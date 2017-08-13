class Solution {
public:
    /*
     * @param nums: An integer
     * @return: 
     */
    
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        if(nums.empty()){return;}
        int i = 0; 
        for(; i < nums.size(); i++){
            if(nums[i - 1] > nums[i]){break;}
        }
        if(i == nums.size()){return;}
        
        reverse(nums.begin(), nums.begin() + i);
        reverse(nums.begin() + i, nums.end());
        reverse(nums.begin(), nums.end());
    }
    
};