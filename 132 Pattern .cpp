class Solution {
public:
    /*
     * @param nums: a list of n integers
     * @return: true if there is a 132 pattern or false
     */
    bool find132pattern(vector<int> &nums) {
        // write your code here
        if(nums.size() < 3){return false;}
        
        stack<pair<int, int>> s;
        pair<int,int> cur = make_pair(nums[0], nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(cur.first >= nums[i]){
                //1(cur) < 3(nums[i]) otherwise 
                s.push(cur);
                cur = {nums[i], nums[i]};
            }else if(cur.first < nums[i] && nums[i] < cur.second){
                return true;
            }else if(cur.second == nums[i]){
                //cur.second <= nums[i]
                //nothing
            }else{
                //cur.second < nums[i]
                while(!s.empty()){
                    auto p = s.top();
                    if(p.second <= nums[i]){
                        s.pop();
                    }else{
                        if(p.first < nums[i]){
                            return true;
                        }else{
                            break;
                        }
                    }
                }
                cur.second = nums[i];
            }
        }
        return false;
    }
};