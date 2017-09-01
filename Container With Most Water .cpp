class Solution {
public:
    /*
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int result = 0;
        int len = heights.size();
        if(len <= 1){return 0;}
        
        int r = len - 1;
        int l = 0;
        while(l < r){
            result = max(result, (r - l) * (heights[l] < heights[r] ? heights[l++] : heights[r--]));
        }
        
        return result;
    }
};