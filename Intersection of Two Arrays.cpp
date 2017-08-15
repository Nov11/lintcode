class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto iter1 = unique(nums1.begin(), nums1.end());
        auto iter2 = unique(nums2.begin(), nums2.end());
        
        vector<int> result;
        auto i1 = nums1.begin();
        auto i2 = nums2.begin();
        while(i1 != iter1 && i2 != iter2){
            if(*i1 == *i2){result.push_back(*i1); i1++;i2++;}
            else{
                if(*i1 < *i2){
                    i1++;
                }else{
                    i2++;
                }
            }
        }
        
        return result;
    }
};