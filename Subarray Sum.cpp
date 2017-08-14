class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        unordered_map<int,int> hash;
        hash[0] = 0;
        int acc = 0;
        for(int i = 0; i < nums.size(); i++){
            acc += nums[i];
            if(hash.find(acc) != hash.end()){return {hash[acc], i};}
            else{hash[acc] = i + 1;}
        }
        return {};
    }
};