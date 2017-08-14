class Solution {
public:

	/*
	* @param digits: a number represented as an array of digits
	* @return: the result
	*/
	vector<int> plusOne(vector<int> digits) {
		// write your code here
		if (digits.empty()) { return { 1 }; }

		int carry = 1;
		int len = digits.size();
		for (int i = len - 1; i >= 0 && carry; i--) {
			digits[i] += carry;
			if (digits[i] > 9) { carry = 1; digits[i] = 0; }
			else { carry = 0; }
		}
		if (carry) {
			// digits.insert(digits.begin(), 1);
			digits.clear();
			digits.resize(len + 1);
			digits[0] = 1;
		}

		return digits;
	}
};