class Solution {
public:
	/*
	* @param heights: a matrix of integers
	* @return: an integer
	*/
	int trapRainWater(vector<vector<int>> &heights) {
		// write your code here
		int m = heights.size();
		if (m <= 1) { return 0; }
		int n = heights[0].size();
		if (n <= 1) { return 0; }

		vector<vector<bool>> v(m, vector<bool>(n));
		priority_queue<pair<int, int>, vector<pair<int, int>>, std::function<bool(const pair<int, int>&, const pair<int, int>)>>
			q([&](const pair<int, int>&p1, const pair<int, int>&p2) {
			int a = heights[p1.first][p1.second];
			int b = heights[p2.first][p2.second];
			return a > b;
		});
		for (int i = 0; i < n; i++) {
			if (i == 0 || i + 1 == n) {
				for (int j = 0; j < m; j++) {
					q.push(make_pair(j, i));
					v[j][i] = true;
				}
			}
			else {
				v[m - 1][i] = true;
				v[0][i] = true;
				q.push(make_pair(0, i));
				q.push(make_pair(m - 1, i));
			}

		}

		int result = 0;
		int h = 0;
		int row[4] = { 0,0,1,-1 };
		int col[4] = { 1,-1,0,0 };
		while (!q.empty()) {
			auto item = q.top();
			q.pop();
			h = max(h, heights[item.first][item.second]);
			for (int i = 0; i < 4; i++) {
				int x = item.first + row[i];
				int y = item.second + col[i];
				if (x >= 0 && x < m && y >= 0 && y < n) {
					if (v[x][y]) {
						continue;
					}
					v[x][y] = true;
					if (h > heights[x][y]) {
						result += h - heights[x][y];
					}
					q.push(make_pair(x, y));
				}
			}
		}

		return result;
	}

};