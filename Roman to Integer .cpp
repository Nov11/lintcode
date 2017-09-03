class Solution {
	unordered_map<char, int> hash{
		{ 'I', 1 },
		{ 'V', 5 },
		{ 'X', 10 },
		{ 'L', 50 },
		{ 'C', 100 },
		{ 'D', 500 },
		{ 'M', 1000 }
	};
public:
	/*
	* @param s: Roman representation
	* @return: an integer
	*/
	int romanToInt(string &s) {
		// write your code here

		int len = s.size();
		if (len == 0) {
			return 0;
		}
		int result = hash[s[len - 1]];
		for (int i = len - 2; i >= 0; i--) {
			int cur = hash[s[i]];
			int prev = hash[s[i + 1]];
			if (cur < prev) {
				result -= cur;
			}
			else {
				result += cur;
			}
		}

		return result;
	}
};