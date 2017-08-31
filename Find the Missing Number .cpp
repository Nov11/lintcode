class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] == i || nums[i] == len){continue;}
            swap(nums[i], nums[nums[i]]);
            i--;
        }
        
        for(int i = 0; i < len; i++){
            if(nums[i] != i){
                return i;
            }
        }
        return len;
    }
};