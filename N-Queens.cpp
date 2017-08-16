class Solution {
	vector<vector<string>> result;
	void work(int cur, int n, int left, int up, int right, vector<string>& ans) {
		if (cur == n) { 
			result.push_back(ans); return; }
		int mask = left;
		mask |= up;
		mask |= right;
		for (int i = 0; i < n; i++) {
			int tmp = 1 << i;
			if ((mask & tmp) == 0) {
				string line = gene(n, tmp);
				ans.push_back(line);
				work(cur + 1, n, (left | tmp) << 1, up | tmp, (right | tmp) >> 1, ans);
				ans.pop_back();
			}
		}
	}
	string gene(int n, int mask) {
		string result(n, '.');
		for (int i = 0; i < n; i++) {
			if (((1 << i) & mask)) {
				result[n - i - 1] = 'Q';
				break;
			}
		}
		return result;
	}
public:
	/**
	* Get all distinct N-Queen solutions
	* @param n: The number of queens
	* @return: All distinct solutions
	* For example, A string '...Q' shows a queen on forth position
	*/
	vector<vector<string> > solveNQueens(int n) {
		// write your code here
		for (int i = 0; i < n; i++) {
			int mask = 1 << i;
			string s = gene(n, mask);
			vector<string> ans{ s };
			work(1, n, mask << 1, mask, mask >> 1, ans);
		}
		return result;
	}
};