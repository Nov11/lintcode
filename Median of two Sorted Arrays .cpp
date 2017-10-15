class Solution {
public:
	int find(vector<int>& A, int ba, int ea, vector<int>& B, int bb, int eb, int k) {
		int sa = ea - ba;
		int sb = eb - bb;
		if (sa > sb) {
			return find(B, bb, eb, A, ba, ea, k);
		}

		if (sa == 0) {
			return B[bb + k - 1];
		}

		if (k == 1) {
			return min(A[ba], B[bb]);
		}

		int cnta = min(sa, k / 2);
		int cntb = k - cnta;

		if (A[ba + cnta - 1] == B[bb + cntb - 1]) {
			return A[ba + cnta - 1];
		}
		else if (A[ba + cnta - 1] < B[bb + cntb - 1]) {
			return find(A, ba + cnta, ea, B, bb, eb, k - cnta);
		}
		return find(A, ba, ea, B, bb + cntb, eb, k - cntb);
	}
public:
	/*
	* @param A: An integer array
	* @param B: An integer array
	* @return: a double whose format is *.5 or *.0
	*/
	double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
		// write your code here
		int len = A.size() + B.size();
		if (len % 2) {
			return find(A, 0, A.size(), B, 0, B.size(), len / 2 + 1);
		}
		return (find(A, 0, A.size(), B, 0, B.size(), len / 2) + find(A, 0, A.size(), B, 0, B.size(), len / 2 + 1)) * 1.0 / 2;
	}
};