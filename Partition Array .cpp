class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        // int p = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] < k){swap(nums[p++], nums[i]);}
        // }
        // return p;
        
        int len = nums.size();
        int i = 0;
        int j = len - 1;
        while(i <= j){
            while(i <= j && nums[i] < k){i++;}
            while(i <= j && nums[j] >= k){j--;}
            if(i <= j){
                swap(nums[i++], nums[j--]);
            }
        }
        return i;
    }
};