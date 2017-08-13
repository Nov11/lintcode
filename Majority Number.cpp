class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int n;
        int cnt = 0;
        for(auto item : nums){
            if(cnt == 0){
                cnt = 1;
                n = item;
            }else if(item == n){
                cnt++;
            }else{cnt --;}
        }
        
        return n;
    }
};
