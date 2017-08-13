class Solution {
    int partition(vector<int>& nums, int beg, int end){
        if(beg + 1 == end){return beg;}
        int i = beg;
        int j = end;
        int pivot = nums[beg];
        while(true){
            while(++i < end && nums[i] < pivot);
            while(--j >= beg && nums[j] > pivot);
            
            if(i < j){
                swap(nums[i], nums[j]);
            }else{
                break;
            }
        }
        
        swap(nums[beg], nums[j]);
        return j;
    }
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(len <= 0){return 0;}
        int target = len / 2;
        if(len % 2 == 0){target -= 1;}
        int beg = 0;
        int end = len;
        while(true){
            int ret = partition(nums, beg, end);
            if(ret == target){break;}
            else if(ret < target){
                beg = ret + 1;
            }else{
                end = ret;
            }
        }
        
        return nums[target];
    }
};
