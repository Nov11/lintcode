class Solution {
public:
	/*
	* @param K: An integer
	* @param prices: An integer array
	* @return: Maximum profit
	*/
	int maxProfit(int K, vector<int> &prices) {
		// write your code here
		if (prices.size() <= 1) {
			return 0;
		}
		if (K >= prices.size() / 2) {
			int result = 0;
			for (int i = 1; i < prices.size(); i++) {
				if (prices[i] > prices[i - 1]) {
					result += prices[i] - prices[i - 1];
				}
			}
			return result;
		}

		int len = prices.size();
		vector<int> global(len);
		vector<int> g(len);
		for (int k = 1; k <= K; k++) {

			int l = 0;
			for (int i = 1; i < len; i++) {

				int diff = prices[i] - prices[i - 1];
				l = max(l + diff, max((i - 2 >= 0 ? global[i - 2] + diff : 0), global[i - 1]));
				g[i] = max(g[i - 1], l);
			}
			swap(g, global);
		}

		return global[len - 1];
	}
};