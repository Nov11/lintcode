class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        if(nums.size() < 2){return {};}
        map<long long, int> hash;
        
        for(int i = 0; i < nums.size(); i++){
            long long val = target - nums[i];
            if(hash.find(val) != hash.end()){
                return {1 + hash[val], i + 1};   
            }else{
                hash[nums[i]] = i;
            }
        }
        return {};
    }
};
