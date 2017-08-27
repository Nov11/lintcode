class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int len = A.size();
        if(len <= 1){return 0;}
        
        vector<vector<int>> dp(len, vector<int>(101, INT_MAX));
        for(int i = 1; i < 101; i++){
            dp[0][i] = abs(i - A[0]);
        }
        
        for(int i = 1; i < len; i++){
            for(int j = 1; j < 101; j++){
                int beg = max(1, j - target);
                int end = min(100, j + target);
                for(int k = beg; k <= end; k++){
                    dp[i][j] = min(dp[i - 1][k] + abs(j - A[i]), dp[i][j]);
                }
            }
        }
        
        int result = INT_MAX;
        for(auto item : dp[len - 1]){
            result = min(result, item);
        }
        
        return result;
    }
};