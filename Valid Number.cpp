class Solution {
public:
	/*
	* @param s: the string that represents a number
	* @return: whether the string is a valid number
	*/
	bool isNumber(string &s) {
		// write your code here
		int idx = 0;
		while (idx < s.size() && s[idx] == ' ') {
			idx++;
		}
		if (idx == s.size()) {
			return false;
		}

		if (s[idx] == '-' || s[idx] == '+') {
			idx++;
		}

		if (idx == s.size()) {
			return false;
		}

		int pos = idx;
		while (idx < s.size() && isdigit(s[idx])) {
			idx++;
		}

		bool noInt = false;
		if (pos == idx) {
			noInt = true;
		}
		if (pos == idx && s[idx] != '.') {
			return false;
		}

		if (idx - pos >= 2 && s[pos] == '0' && s[pos + 1] == '0') {
			return false;
		}

		if (idx == s.size()) {
			return true;
		}

		if (s[idx] == '.') {
			idx++;
			pos = idx;
			while (idx < s.size() && isdigit(s[idx])) {
				idx++;
			}

			if (idx == pos && noInt) {
				return false;
			}
		}

		if (idx == s.size()) {
			return true;
		}

		if (s[idx] == 'e' || s[idx] == 'E') {
			idx++;
			if (s[idx] == '-' || s[idx] == '+') {
				idx++;
			}

			pos = idx;
			while (idx < s.size() && isdigit(s[idx])) {
				idx++;
			}

			if (pos == idx) {
				return false;
			}

			if (idx - pos >= 2 && s[pos] == '0' && s[pos + 1] == '0') {
				return false;
			}
		}

		if (idx == s.size()) {
			return true;
		}


		while (idx < s.size() && s[idx] == ' ') {
			idx++;
		}

		return idx == s.size();
	}
};