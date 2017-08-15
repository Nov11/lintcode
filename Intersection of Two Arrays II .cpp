class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        unordered_map<int, int> hash;
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        
        int cnt = 0;
        for(auto item : nums1){
            hash[item]++;
            cnt++;
        }
        
        vector<int> result;
        for(int i = 0; i < nums2.size() && cnt > 0; i++){
            auto iter = hash.find(nums2[i]);
            if(iter == hash.end()){
                continue;
            }
            result.push_back(nums2[i]);
            cnt--;
            if(--iter->second == 0){
                hash.erase(iter);
            }
        }
        
        return result;
    }
};