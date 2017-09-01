class Solution {
public:
    /*
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> heights) {
        // write your code here
        if(heights.size() <= 2){return 0;}
        int l = 0;
        int r = heights.size() - 1;
        
        int result = 0;
        while(l < r - 1){
            if(heights[l] < heights[r]){
                int i = l++;
                for(; l < r; l++){
                    if(heights[l] < heights[i]){
                        result += heights[i] - heights[l];
                    }else{
                        break;
                    }
                }
            }else{
                int i = r--;
                for(; r > l; r--){
                    if(heights[r] < heights[i]){
                        result += heights[i] - heights[r];
                    }else{
                        break;
                    }
                }
            }
        }
        
        return result;
    }
};