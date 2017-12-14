class Solution {
	void work(vector<int>& A, vector<pair<int, int>>& cur, int b, int e) {
		if (b + 1 >= e) {
			return;
		}
		int mid = b + (e - b) / 2;
		work(A, cur, b, mid);
		work(A, cur, mid, e);

		int i = b;
		int j = mid;
		vector<pair<int, int>> tmp;
		int smaller = 0;
		while (i < mid && j < e) {
			pair<int, int> left = cur[i];
			pair<int, int> right = cur[j];

			if (A[left.first] <= A[right.first]) {
				if (A[left.first] < A[right.first]) { smaller++; }
				tmp.push_back(left);
				i++;
			}
			else {
				right.second += smaller;
				tmp.push_back(right);
				j++;
				if (j < e && A[right.first] != A[cur[j].first]) {
					smaller = i - b;
				}
			}
		}

		while (i < mid) {
			tmp.push_back(cur[i]);
			i++;
		}

		while (j < e) {
			cur[j].second += smaller;
			tmp.push_back(cur[j]);
			j++;
			if (j < e && A[cur[j - 1].first] != A[cur[j].first]) {
				smaller = i - b;
			}
		}

		copy(tmp.begin(), tmp.end(), cur.begin() + b);
	}
public:
	/*
	* @param A: an integer array
	* @return: A list of integers includes the index of the first number and the index of the last number
	*/
	vector<int> countOfSmallerNumberII(vector<int> &A) {
		// write your code here
		int n = A.size();
		vector<pair<int, int>> cur;
		for (int i = 0; i < n; i++) {
			cur.push_back(make_pair(i, 0));
		}

		work(A, cur, 0, n);

		vector<int> result(n);

		for (int i = 0; i < n; i++) {
			result[cur[i].first] = cur[i].second;
		}

		return result;
	}
};