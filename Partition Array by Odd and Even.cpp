class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){swap(nums[idx], nums[i]); idx++;}
        }
    }
};