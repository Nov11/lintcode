class Solution {
    int binarySearch(vector<int>& nums, int beg, int end, int target){
        if(beg >= end){return -1;}
        while(beg < end){
            int mid = beg + (end - beg) / 2;
            if(nums[mid] == target){return mid;}
            else if(nums[mid] < target){beg = mid + 1;}
            else{end = mid;}
        }
        return -1;
    }
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(len < 3){return {};}
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]){continue;}
            for(int j = i + 1; j < len - 1; j++){
                if(j != i + 1 && nums[j] == nums[j - 1]){continue;}
                int target = 0 - nums[i] - nums[j];
                int k = binarySearch(nums, j + 1, len, target);
                if(k!=-1){
                    result.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        
        return result;
    }
};
