class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string A, string B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        if(m == 0 || n == 0){return 0;}
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        int result = 0;
        for(int i = 1; i < m + 1; i ++){
            for(int j = 1; j < n + 1; j++){
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = max(result, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
};