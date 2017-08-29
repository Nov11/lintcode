class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        int len = nums.size();
        if(len == 0){return {};}
        if(len == 1){return {0, 0};}
        
        vector<pair<int,int>> v(len + 1);
        for(int i = 0; i < len; i++){
            v[i + 1] = make_pair(nums[i] + v[i].first, i);
        }
        sort(v.begin()+1, v.end(), [](const pair<int,int>& p1, const pair<int,int>&p2){return p1.first< p2.first;});
        
        int diff = INT_MAX;
        vector<int> result(2);
        for(int i = 2; i <= len; i++){
            if(diff > v[i].first - v[i - 1].first){
                diff = v[i].first - v[i - 1].first;
                result[0] = (v[i].second < v[i - 1].second ? v[i].second : v[i - 1].second) + 1;
                result[1] = v[i].second < v[i - 1].second ? v[i - 1].second : v[i].second;
            }
        }
        
        return result;
    }
};
