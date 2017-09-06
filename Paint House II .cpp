class Solution {
	void updateMin(int& minFst, int& minSnd, vector<vector<int>> &dp, int idx, int k) {
		minFst = -1;
		minSnd = -1;
		for (int i = 0; i < k; i++) {
			if (minFst == -1) { minFst = i; }
			else if (dp[idx][minFst] > dp[idx][i]) {
				minSnd = minFst;
				minFst = i;
			}
			else if (minSnd == -1) { minSnd = i; }
			else if (dp[idx][minSnd] > dp[idx][i]) {
				minSnd = i;
			}
		}
	}
public:
	/*
	* @param costs: n x k cost matrix
	* @return: an integer, the minimum cost to paint all houses
	*/
	int minCostII(vector<vector<int>> &costs) {
		// write your code here
		int n = costs.size();
		if (n == 0) { return 0; }
		int k = costs[0].size();
		if (k <= 1) { return 0; }

		vector<vector<int>> dp(n, vector<int>(k));
		dp[0] = costs[0];
		int minFst = -1;
		int minSnd = -1;
		updateMin(minFst, minSnd, dp, 0, k);

		for (int iter = 1; iter < n; iter++) {
			for (int i = 0; i < k; i++) {
				dp[iter][i] = costs[iter][i] + (i == minFst ? dp[iter - 1][minSnd] : dp[iter - 1][minFst]);
			}

			updateMin(minFst, minSnd, dp, iter, k);
		}

		return dp[n - 1][minFst];
	}
};