class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int m = matrix.size();
        if(m == 0){return 0;}
        int n = matrix[0].size();
        if(n == 0){return 0;}
        
        vector<vector<int>> dp(m, vector<int>(n));
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){continue;}
                if(i == 0 || j == 0){dp[i][j] = 1;}
                else{
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};