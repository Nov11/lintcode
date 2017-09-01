class Solution {
	int factorial(int p) {
		if (p == 0 || p == 1) { return 1; }
		int result = 1;
		for (int i = 2; i <= p; i++) {
			result *= i;
		}
		return result;
	}
public:
	/*
	* @param n: n
	* @param k: the k th permutation
	* @return: return the k-th permutation
	*/
	string getPermutation(int n, int k) {
		// write your code here
		set<int> s;
		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}
		string result;

		for (int i = 1; i <= n; i++) {
			int number = (k - 1) / factorial(n - i);
			auto iter = s.begin();
			advance(iter, number);
			result.push_back('0' + *iter);
			s.erase(iter);

			k %= factorial(n - i);
			if (k == 0) {
				for (auto riter = s.rbegin(); riter != s.rend(); riter++) {
					result.push_back('0' + *riter);
				}
				break;
			}
		}
		return result;
	}
};