class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(len == 1){return nums[0];}
        
        if(nums.front() < nums.back()){
            return nums.front();
        }
        
        int b = 0;
        int e = len;
        while(b < e){
            if(b + 1 == e){return nums[b];}
            if(nums[b] < nums[e - 1]){return nums[b];}
            
            int mid = b + (e - b) / 2;
            if(nums[mid] > nums[b]){
                b = mid + 1;
            }else{
                e = mid + 1;
                b++;
            }
        }
    }
};