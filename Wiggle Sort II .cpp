class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        if(nums.size() <= 1){return;}
        
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        int high = nums.size() - 1;
        int low = high / 2;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2){
                tmp.push_back(nums[high--]);
            }else{
                tmp.push_back(nums[low--]);
            }
        }
        swap(nums, tmp);
    }
};