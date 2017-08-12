class Solution {
public:
	/**
	* @param A and B: sorted integer array A and B.
	* @return: A new sorted integer array
	*/
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
		// write your code here
		vector<int> result;
		auto iterA = A.begin();
		auto iterB = B.begin();
		while (iterA != A.end() || iterB != B.end()) {
			if (iterA == A.end()) { result.push_back(*iterB++); }
			else if (iterB == B.end()) { result.push_back(*iterA++); }
			else if (*iterA < *iterB) { result.push_back(*iterA++); }
			else { result.push_back(*iterB++); }
		}

		return result;
	}
};