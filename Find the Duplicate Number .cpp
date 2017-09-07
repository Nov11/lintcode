class Solution {
public:
    /**
     * @param nums an array containing n + 1 integers which is between 1 and n
     * @return the duplicate one
     */
    int findDuplicate(vector<int>& nums) {
        // Write your code here
        int len = nums.size();
        int n = len - 1;
        int beg = 1; 
        int end = n;
        while(beg < end){
            int mid = beg + (end - beg) / 2;
            int cnt = 0;
            for(auto item : nums){
                if(item <= mid){cnt++;}
            }
            
            if(cnt > mid){
                end = mid;
            }else{
                beg = mid + 1;
            }
        }
        
        return beg;
    }
};