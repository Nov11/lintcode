class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> hash;
        for(int item : nums){
            if(hash.find(item) != hash.end()){
                hash[item]++;
                continue;
            }
            if(hash.size() < k - 1){
                hash[item]++;
                continue;
            }
            if(hash.size() == k - 1){
                for(auto iter = hash.begin(); iter != hash.end();){
                    if(--iter->second){
                        iter = hash.erase(iter);
                    }
                }
            }
        }
        
        for(auto& item : hash){
            item.second = 0;
        }
        
        int result = 0;
        int cnt = 0;
        for(auto item : nums){
            hash[item]++;
            if(hash[item] > cnt){
                cnt = hash[item];
                result = item;
            }
        }
        
        return result;
    }
};
