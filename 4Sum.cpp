class Solution {
    int binarySearch(vector<int>& nums, int beg, int end, int target){
        if(beg >= end){return -1;}
        while(beg < end){
            int mid = beg + (end - beg) / 2;
            if(nums[mid] == target){return mid;}
            else if(nums[mid] < target){beg = mid + 1;}
            else {end = mid;}
        }
        return -1;
    }
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        int len = nums.size();
        if(len < 4){return {};}
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for(int i = 0; i < len - 3; i++){
            if(i != 0 && nums[i] == nums[i - 1]){continue;}
            for(int j = i + 1; j < len -2; j++){
                if(j != i + 1 && nums[j] == nums[j - 1]){continue;}
                for(int k = j + 1; k < len - 1; k++){
                    if(k != j + 1 && nums[k] == nums[k - 1]){continue;}
                    int t = target - nums[i] - nums[j] - nums[k];
                    int m = binarySearch(nums, k + 1, len, t);
                    if(m != -1){
                        result.push_back({nums[i], nums[j], nums[k], nums[m]});
                    }
                }
            }
        }
        
        return result;
    }
};
