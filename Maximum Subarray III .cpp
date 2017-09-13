class Solution {
public:
	/*
	* @param nums: A list of integers
	* @param k: An integer denote to find k non-overlapping subarrays
	* @return: An integer denote the sum of max k non-overlapping subarrays
	*/
	int maxSubArray(vector<int> &nums, int k) {
		// write your code here
		int len = nums.size();
		if (k <= 0 || len < k) { return 0; }

		vector<vector<int>> dp(len + 1, vector<int>(k + 1));
		vector<vector<int>> dp2{ dp };

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][i] += nums[j - 1];
			}
			dp2[i][i] = dp[i][i];

			for (int j = i + 1; j <= len; j++) {
				dp[j][i] = max(dp[j - 1][i] + nums[j - 1], dp2[j - 1][i - 1] + nums[j - 1]);
				dp2[j][i] = max(dp2[j - 1][i], dp[j][i]);
			}
		}

		return dp2[len][k];
	}
};