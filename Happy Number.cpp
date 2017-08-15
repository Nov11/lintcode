class Solution {
public:

	/*
	* @param n: An integer
	* @return: true if this is a happy number or false
	*/
	bool isHappy(int n) {
		// write your code here
		if (n <= 0) { return false; }

		unordered_set<int> s;

		while (n != 1 && s.find(n) == s.end()) {
		    s.insert(n);
			int tmp = 0;
			while (n) {
				int d = n % 10;
				tmp += d * d;
				n /= 10;
			}
			if (tmp == 1) { return true; }
			swap(tmp, n);
		}

        return n == 1;
	}
};