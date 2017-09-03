class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int len = nums.size();
        if(len == 0){return -1;}
        int beg = 0;
        int cur = 0;
        int sum = 0;
        int result = INT_MAX;
        while(cur < len){
            if(sum + nums[cur] >= s){
                result = min(result, cur - beg + 1);
                sum -= nums[beg];
                beg++;
            }else{
                sum += nums[cur];
                cur++;
            }
        }
        return result == INT_MAX ? -1 : result;;
    }
};