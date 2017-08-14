class Solution {

public:
	/*
	* @param A: An array of integers
	* @return: A long integer
	*/
	long long permutationIndex(vector<int> A) {
		// write your code here
		if (A.empty()) { return 0; }
		vector<long long> d{ 1, 1 };
		for (int i = 2; i < A.size(); i++) {
			d.push_back(d[i - 1] * i);
		}

// 		vector<int> rank(A);
// 		sort(rank.begin(), rank.end());
		long long result = 1;
		int len = A.size();
		for (int i = 0; i < len - 1; i++) {
			int digit = A[i];
			int cnt = 0;
			for(int j = i + 1; j < len; j++){
			    if(A[j] < digit){cnt++;}
			}

			result += cnt * d[len - i - 1];
// 			rank.erase(rank.begin() + cnt);
		}

		return result;
	}
};