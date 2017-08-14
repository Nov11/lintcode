class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.empty()){return 0;}
        
        int prev = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[prev] || (prev - 1 < 0 || nums[prev - 1] != nums[prev])){
                nums[++prev] = nums[i];
            }
        }
        
        return prev + 1;
    }
};