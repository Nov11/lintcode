class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(len <= 1){return;}
        
        int one = 0;
        int two = len - 1;
        
        for(int i = 0; i <= two; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[one]);
                one++;
            }else if(nums[i] == 1){
                //nothing
            }else{
                swap(nums[i], nums[two]);
                i--;
                two--;
            }
        }
    }
};