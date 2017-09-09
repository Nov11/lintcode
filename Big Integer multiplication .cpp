class Solution {
	string add(string s1, string s2) {
		if (s1.empty() || s1 == "0") { return s2; }
		if (s2.empty() || s2 == "0") { return s1; }

		if (s1.size() < s2.size()) {
			swap(s1, s2);
		}
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());

		string result;
		int carry = 0;
		int i = 0;
		for (; i < s2.size(); i++) {
			int sum = s1[i] - '0' + s2[i] - '0' + carry;
			result.push_back(sum % 10 + '0');
			carry = sum / 10;
		}

		while (carry != 0) {
			if (i < s1.size()) {
				int sum = s1[i] - '0' + carry;
				result.push_back(sum % 10 + '0');
				carry = sum / 10;
				i++;
			}
			else {
				result.push_back('1');
				carry = 0;
			}
		}

		while (i < s1.size()) {
			result.push_back(s1[i]);
			i++;
		}

		reverse(result.begin(), result.end());
		return result;
	}

	string mul10(string num, int cnt) {
		if (num.empty() || num == "0") { return num; }

		string zeros;
		for (int i = 0; i < cnt; i++) {
			zeros.push_back('0');
		}
		return num + zeros;
	}

	string mul(string s1, int n) {
		if (n == 0) { return "0"; }
		reverse(s1.begin(), s1.end());
		int carry = 0;
		string result;
		for (int i = 0; i < s1.size(); i++) {
			int v = (s1[i] - '0') * n + carry;
			result.push_back(v % 10 + '0');
			carry = v / 10;
		}
		if (carry) {
			result.push_back(carry + '0');
		}

		reverse(result.begin(), result.end());
		return result;
	}
public:
	/*
	* @param num1: a non-negative integers
	* @param num2: a non-negative integers
	* @return: return product of num1 and num2
	*/
	string multiply(string &num1, string &num2) {
		// write your code here
		if (num1.empty() || num2.empty()) { return ""; }
		if (num1.size() < num2.size()) {
			swap(num1, num2);
		}

		string result;
		int cnt = 0;
		for (auto riter = num2.rbegin(); riter != num2.rend(); riter++) {
			string tmp = mul(num1, *riter - '0');
			tmp = mul10(tmp, cnt);
			cnt++;
			result = add(result, tmp);
		}

		return result;
	}
};