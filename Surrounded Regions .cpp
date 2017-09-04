class Solution {
	void dfs(vector<vector<char>>& board, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n) { return; }
		if (board[i][j] == 'X' || board[i][j] == '!') { return; }
		board[i][j] = '!';
		for (int iter = 0; iter < 4; iter++) {
			dfs(board, i + row[iter], j + col[iter]);
		}
	}
	int m;
	int n;
	int row[4] = { 1,-1,0,0 };
	int col[4] = { 0,0,1,-1 };
public:
	/**
	* @param board a 2D board containing 'X' and 'O'
	* @return void
	*/
	void surroundedRegions(vector<vector<char>>& board) {
		// Write your code here
		m = board.size();
		if (m == 0) { return; }
		n = board[0].size();
		if (n == 0) { return; }

		for (int i = 0; i < m; i++) {
			dfs(board, i, 0);
			dfs(board, i, n - 1);
		}

		for (int j = 1; j < n - 1; j++) {
			dfs(board, 0, j);
			dfs(board, m - 1, j);
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '!') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
};