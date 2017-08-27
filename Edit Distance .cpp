class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int m = word1.size();
		int n = word2.size();

		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		for (int i = 0; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int j = 0; j <= n; j++) {
			dp[0][j] = j;
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				int add = dp[i - 1][j] + 1;
				int del = dp[i][j - 1] + 1;
				int mod = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;

				dp[i][j] = min(del, min(add, mod));
			}
		}

		return dp[m][n];
    }
};
