class Solution {
public:
    /*
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int t = target - nums[i];
            int b = i + 1;
            int e = len;
            while(b < e){
                int mid = b + (e - b) / 2;
                if(nums[mid] == t){
                    return {i + 1, mid + 1};
                }else if(nums[mid] < t){
                    b = mid + 1;
                }else{
                    e = mid;
                }
            }
        }
        return {};
    }
};