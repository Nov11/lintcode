class Solution {
public:
	/*
	* @param matrix: An array of integers
	* @return: An array of integers
	*/
	vector<int> printZMatrix(vector<vector<int>> matrix) {
		// write your code here
		int m = matrix.size();
		if (m == 0) { return {}; }
		int n = matrix[0].size();
		if (n == 0) { return {}; }

		vector<int> result;
		int i = 0;
		int j = 0;
		bool up = true;
		while (result.size() != m * n) {
			result.push_back(matrix[i][j]);

			if (i == m - 1 && !up) {
				j++; up = !up;
			}
			else if (j == n - 1 && up) {
				i++; up = !up;
			}
			else if (i == 0 && up) {
				j++; up = !up;
			}
			else if (j == 0 && !up) {
				i++; up = !up;
			}
			else {
				if (up) { i--; j++; }
				else { i++; j--; }
			}
		}

		return result;
	}
};