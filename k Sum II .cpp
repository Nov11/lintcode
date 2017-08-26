class Solution {
	vector<vector<int>> result;
	void dfs(vector<int>& path, vector<int>& A, int k, int target, int i) {
		if (k <= 0 || i >= A.size()) { return; }
		if (k == 1 && target != A[i]) { return; }
		if (k == 1) {
			path.push_back(A[i]);
			result.push_back(path);
			path.pop_back();
			return;
		}

		path.push_back(A[i]);
		for (int j = i + 1; j < A.size(); j++) {
			dfs(path, A, k - 1, target - A[i], j);
		}
		path.pop_back();
	}
public:
	/*
	* @param A: an integer array
	* @param k: a postive integer <= length(A)
	* @param targer: an integer
	* @return: A list of lists of integer
	*/
	vector<vector<int>> kSumII(vector<int> A, int k, int target) {
		// write your code here
		sort(A.begin(), A.end());
		vector<int> path;
		for (int i = 0; i < A.size(); i++) {
			dfs(path, A, k, target, i);
		}

		return result;
	}
};