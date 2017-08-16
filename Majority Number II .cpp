class Solution {
    //not come up with my own
    //LOL
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cnt1 = 0;
        int n1;
        int cnt2 = 0;
        int n2;
        
        for(auto item : nums){
            if(cnt1 && n1 == item){cnt1++;}
            else if(cnt2 && n2 == item){cnt2++;}
            else if(cnt1 == 0){cnt1 = 1; n1 = item;}
            else if(cnt2 == 0){cnt2 = 1; n2 = item;}
            else{cnt1 --; cnt2--;}
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for(auto item : nums){
            if(item == n1){cnt1++;}
            else if(item == n2){cnt2++;}
        }
        
        return cnt1 > cnt2 ? n1 : n2;
    }
};
