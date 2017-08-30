class Solution {
public:
    /*
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> nums) {
        // write your code here
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        if(nums[0] == 0){return "0";}
        string result;
        for(auto item : nums){
            result.append(to_string(item));
        }
        return result;
    }
};