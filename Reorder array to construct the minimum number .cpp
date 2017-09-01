class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) < to_string(b) + to_string(a);
        });
        
        string result;
        for(auto item : nums){
            if(result.empty() && item == 0){continue;}
            result.append(to_string(item));
        }
        return result.empty() ? "0" : result;
    }
};