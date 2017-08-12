class Solution {
public:
	/*
	* @param n an integer
	* @return the nth prime number as description.
	*/
	int nthUglyNumber(int n) {
		// write your code here
		if (n == 1) { return 1; }
		vector<int> v{ 1,1 };
		int two = 1;
		int three = 1;
		int five = 1;

		for (int i = 1; i < n; i++) {
			int val = v[two] * 2;
			val = min(val, v[three] * 3);
			val = min(val, v[five] * 5);

			v.push_back(val);

			if (val % 2 == 0) { two++; }
			if (val % 3 == 0) { three++; }
			if (val % 5 == 0) { five++; }
		}

		return v.back();
	}
};