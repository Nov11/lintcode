class Solution {
	void add(set<int>& from, int v, set<int>& to) {
		for (auto& item : from) {
			to.insert(item + v);
		}
	}
public:
	/*
	* @param : an array of arrays
	* @return: the sum of all unique weighted paths
	*/
	int uniqueWeightedPaths(vector<vector<int>>& grid) {
		// write your codes here
		int m = grid.size();
		if (m == 0) { return 0; }
		int n = grid[0].size();
		if (n == 0) { return 0; }

		vector<set<int>> v1(n);
		vector<set<int>> v2(n);

		v1[0].insert(grid[0][0]);
		for (int j = 1; j < n; j++) {
			add(v1[j - 1], grid[0][j], v1[j]);
		}

		for (int i = 1; i < m; i++) {
			v2[0].clear();
			add(v1[0], grid[i][0], v2[0]);
			for (int j = 1; j < n; j++) {
				v2[j].clear();
				add(v1[j], grid[i][j], v2[j]);
				add(v2[j - 1], grid[i][j], v2[j]);
			}
			swap(v1, v2);
		}

		return accumulate(v1[n - 1].begin(), v1[n - 1].end(), 0);
	}
};