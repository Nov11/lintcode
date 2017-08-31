class Solution {
	//well, farewell Autodesk
	long long factorial(int i) {
		if (i <= 1) { return 1; }
		long long result = 1;
		for (int iter = 2; iter <= i; iter++) {
			result *= iter;
		}
		return result;
	}

	int count(map<int, int>& hash) {
		int result = 0;
		for (auto& item : hash) {
			result += item.second;
		}

		return result;
	}

	long long duplicate(map<int, int>& hash) {
		long long result = 1;
		for (auto& item : hash) {
			result *= factorial(item.second);
		}

		return result;
	}
public:
	/**
	* @param A an integer array
	* @return a long integer
	*/
	long long permutationIndexII(vector<int>& A) {
		// Write your code here
		map<int, int> hash;
		for (auto item : A) {
			hash[item]++;
		}
		long long result = 0;
		int len = A.size();
		for (int i = 0; i < len; i++) {
			auto ret = hash.lower_bound(A[i]);
			for (auto iter = hash.begin(); iter != ret; iter++) {
				iter->second--;
				long long tmp = factorial(count(hash));
				long long dup = duplicate(hash);
				result += tmp / dup;
				iter->second++;
			}
			hash[A[i]]--;
			if (hash[A[i]] == 0) {
				hash.erase(A[i]);
			}
		}

		return result + 1;
	}
};