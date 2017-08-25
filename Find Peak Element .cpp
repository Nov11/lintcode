class Solution {
public:
	/**
	* @param A: An integers array.
	* @return: return any of peek positions.
	*/
	int findPeak(vector<int> A) {
		// write your code here
		int len = A.size();
		if (len <= 2) { return -1; }
		if (A[0] >= A[1] || A[len - 2] <= A[len - 1]) { return -1; }

		int i = 0;
		int j = len;
		int mid = i + (j - i) / 2;

		if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) { 
			return mid; 
		}
		if (A[mid] < A[mid - 1] && A[mid] < A[mid + 1]) {
			vector<int> left(A.begin(), A.begin() + mid + 1);
			vector<int> right(A.begin() + mid, A.end());
			auto rl = findPeak(left);
			if (rl != -1) { return rl; }
			auto rr = findPeak(right);
			if (rr != -1) { return rr + mid; }
		}

		if (A[mid] > A[mid - 1]) {
			vector<int> left(A.begin(), A.begin() + mid);
			while (left.size() >= 2) {
				int llen = left.size();
				if (left[llen - 1] > left[llen - 2]) { left.pop_back(); }
				else { break; }
			}
			auto rl = findPeak(left);
			if (rl != -1) { return rl; }
			vector<int> right(A.begin() + mid, A.end());
			auto rr = findPeak(right);
			if (rr != -1) { return rr + mid; }
		}

		if (A[mid] > A[mid + 1]) {
			vector<int> left(A.begin(), A.begin() + mid + 1);
			auto rl = findPeak(left);
			if (rl != -1) { return rl; }
			vector<int> right(A.begin() + mid + 1, A.end());
			int cnt = 0;
			while (right.size() >= 2) {
				if (right[0] > right[1]) { right = vector<int>(right.begin() + 1, right.end()); cnt++; }
				else {
					break;
				}
			}
			auto rr = findPeak(right);
			if (rr != -1) { return rr + mid + 1 + cnt; }
		}

		return -1;
	}
};