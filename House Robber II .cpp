//this solution will produce TLE in submission. I havn't figure out how to deal with it.

class Solution {
    int work(vector<int>& nums, int beg, int end){
        if(beg >= end){return 0;}
        if(beg + 1 == end){return nums[beg];}
        
        int pp = nums[beg];
        int p = max(nums[beg + 1], pp);
        
        for(int i = 2; i < end - beg; i++){
            int tmp = max(nums[beg + i] + pp, p);
            pp = p;
            p = tmp;
        }
        return p;
    }
public:
    /*
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> nums) {
        // write your code here
        if(nums.empty()){return 0;}
        if(nums.size() == 1){return nums[0];}
        return max(work(nums, 0, nums.size() - 1), work(nums, 1, nums.size()));
    }
};