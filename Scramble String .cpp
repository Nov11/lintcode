class Solution {
public:
	/*
	* @param s1: A string
	* @param s2: Another string
	* @return: whether s2 is a scrambled string of s1
	*/
	bool isScramble(string &s1, string &s2) {
		// write your code here
		if (s1 == s2) { return true; }
		if (s1.size() != s2.size()) { return false; }

		int len = s1.size();
		vector<vector<vector<bool>>> dp(len, vector<vector<bool>>(len, vector<bool>(len + 1)));

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (s1[i] == s2[j]) {
					dp[i][j][1] = true;
				}
			}
		}


		for (int m = 2; m <= len; m++) {
			for (int i = len - m; i >= 0; i--) {
				for (int j = len - m; j >= 0; j--) {
					for (int n = 1; n < m; n++) {
						if (dp[i][j][n] && dp[i + n][j + n][m - n]) {
							dp[i][j][m] = true;
							break;
						}
						else if (dp[i][j + m - n][n] && dp[i + n][j][m - n]) {
							dp[i][j][m] = true;
							break;
						}
					}
				}
			}
		}

		return dp[0][0][len];
	}
};