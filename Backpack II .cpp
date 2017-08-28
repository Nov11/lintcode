class Solution {
public:
    /*
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int n = A.size();
        if(n == 0){return 0;}
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for(int i = 1; i<= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j - 1];
                if(i >= A[j - 1]){
                    dp[i][j] = max(dp[i][j], dp[i - A[j - 1]][j - 1] + V[j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
};