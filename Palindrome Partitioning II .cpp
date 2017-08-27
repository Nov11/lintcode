class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int len = s.size();
		if (len <= 1) { return 0; }

		vector<vector<bool>> dp(len, vector<bool>(len, false));

		for (int j = 0; j < len; j++) {
			dp[j][j] = true;
			for (int i = j - 1; i >= 0; i--) {
				if (s[i] == s[j] && (i + 1 == j || dp[i + 1][j - 1])) {
					dp[i][j] = true;
				}
			}
		}

		vector<int> dp2(len);
		dp2[0] = 0;
		for (int j = 1; j < len; j++) {
			if (dp[0][j]) { dp2[j] = 0; continue; }
			dp2[j] = j;
			for (int i = j; i >= 1; i--) {
				if (dp[i][j]) {
					dp2[j] = min(dp2[j], dp2[i - 1] + 1);
				}
			}
		}

		return dp2[len - 1];
    }
};

