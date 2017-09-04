class Solution {
public:
	/**
	* @param matrix an integer matrix
	* @return the coordinate of the left-up and right-down number
	*/
	vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
		// Write your code here
		int m = matrix.size();
		if (m == 0) { return {}; }
		int n = matrix[0].size();
		if (n == 0) { return {}; }

		// vector<vector<int>> cache(m, vector<int>(n + 1));
		// for(int i = 0; i < m; i++){
		//     for(int j = 1; j < n + 1; j++){
		//         cache[i][j] = cache[i][j - 1] + matrix[i][j - 1];
		//     }
		// }
		vector<vector<int>> sum(matrix);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i - 1 >= 0) { sum[i][j] += sum[i - 1][j]; }
				if (j - 1 >= 0) { sum[i][j] += sum[i][j - 1]; }
				if (i >= 1 && j >= 1) { sum[i][j] -= sum[i - 1][j - 1]; }
			}
		}


		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int p = i; p < m; p++) {
					for (int q = j; q < n; q++) {
						int tmp = 0;
						if (i - 1 >= 0 && j - 1 >= 0) { tmp -= sum[i - 1][j - 1]; }
						if (i - 1 >= 0) { tmp += sum[i - 1][q]; }
						if (j - 1 >= 0) { tmp += sum[p][j - 1]; }
						if (tmp == sum[p][q]) {
							return { { i,j },{ p,q } };
						}
					}
				}
			}
		}
		return {};
	}
};