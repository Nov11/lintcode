class Solution {
public:
	/*
	* @param A: An integer array
	* @param k: A positive integer (k <= length(A))
	* @param target: An integer
	* @return: An integer
	*/
	int kSum(vector<int> &A, int k, int target) {
		// write your code here
		if (k == 0 && target == 0) { return 1; }
		if (k <= 0) { return 0; }
		if (target <= 0) { return 0; }

		if (A.size() < k) { return 0; }

		int len = A.size();

		vector<vector<int>> v(k + 1, vector<int>(target + 1));
		v[0][0] = 1;
		for (int i = 1; i <= len; i++) {
			for (int j = k; j >= 1; j--) {
				for (int t = target; t >= 1; t--) {
					//cur state : i, j, t
					if (t - A[i - 1] >= 0) {
						v[j][t] += v[j - 1][t - A[i - 1]];
					}
				}
			}
		}

		return v[k][target];
	}
	int kSumOld(vector<int> &A, int k, int target) {
		// write your code here
		if (k == 0 && target == 0) { return 1; }
		if (k <= 0) { return 0; }
		if (target <= 0) { return 0; }

		if (A.size() < k) { return 0; }

		int len = A.size();

		vector<vector<vector<int>>> v(len + 1, vector<vector<int>>(k + 1, vector<int>(1 + target)));
		v[0][0][0] = 1;
		for (int t = 1; t <= target; t++) {
			for (int i = 1; i <= len; i++) {
				v[i][0][0] = 1;
				for (int j = 1; j <= k && j <= i; j++) {
					v[i][j][t] = (t - A[i - 1] >= 0 ? v[i - 1][j - 1][t - A[i - 1]] : 0)
						+ (i - 1 >= j ? v[i - 1][j][t] : 0);
					//cout << "v[" << i << "][" << j << "][" << t << "]=" << v[i][j][t] << endl;
				}
			}
		}

		return v[len][k][target];
	}
};