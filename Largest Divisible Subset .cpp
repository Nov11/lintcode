class Solution {
public:
    /**
     * @param nums a set of distinct positive integers
     * @return the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Write your code here
        int len = nums.size();
        if(len <= 1){return nums;}
        sort(nums.begin(), nums.end());
        vector<int> dp(len, 1);
        vector<int> prev(len, -1);
        int maxId = 0;
        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(dp[maxId] < dp[i]){
                maxId = i;
            }
        }
        
        vector<int> result;
        do{
            result.push_back(nums[maxId]);
            maxId = prev[maxId];
        }while(maxId != -1);
        
        return result;
    }
};