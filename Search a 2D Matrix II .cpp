class Solution {
public:
	/**
	* @param matrix: A list of lists of integers
	* @param target: An integer you want to search in matrix
	* @return: An integer indicate the total occurrence of target in the given matrix
	*/
	int searchMatrix(vector<vector<int> > &matrix, int target) {
		// write your code here
		int m = matrix.size();
		if (m == 0) { return 0; }
		int n = matrix[0].size();
		if (n == 0) { return 0; }

		int result = 0;
		int i = 0;
		int j = n - 1;
		while (i < m && j >= 0) {
			if (matrix[i][j] == target) { result++; i++; j--; }
			else if (matrix[i][j] > target) { j--; }
			else { i++; }
		}

		return result;
	}
};
