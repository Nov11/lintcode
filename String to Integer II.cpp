class Solution {
public:
	/*
	* @param str: A string
	* @return: An integer
	*/
	int atoi(string &str) {
		// write your code here
		if (str.empty()) { return 0; }
		string inner;
		{
			int idx = 0;
			while (idx < str.size() && str[idx] == ' ') { idx++; }
			int ridx = str.size();
			ridx--;
			while (ridx > idx && str[ridx] == ' ') { ridx--; }
			for (int i = idx; i <= ridx; i++) {
				inner.push_back(str[i]);
			}
		}
		if (inner.empty()) {
			return 0;
		}

		bool pos = true;
		int idx = 0;
		if (inner[idx] == '-') {
			pos = false;
			idx++;
		}
		else if (inner[idx] == '+') {
			idx++;
		}

		if (idx == inner.size()) {
			return 0;
		}

		while (idx < inner.size() && inner[idx] == '0') {
			idx++;
		}
		if (idx == inner.size()) { return 0; }

		long long result = 0;
		int cnt = 0;
		while (idx < inner.size() && cnt < 11) {
			char c = inner[idx];
			if (c == '.') {
				break;
			}
			if (!isdigit(c)) {
				break;
			}
			result *= 10;
			result += c - '0';
			cnt++;
			idx++;
		}
		////make sure the rest chars are digits
		//while (idx < inner.size()) {
		//	if (!isdigit(inner[idx])) {
		//		return 0;
		//	}
		//	idx++;
		//}
		if (!pos) {
			result = result * -1;
		}
		if (pos && result > INT_MAX) {
			return INT_MAX;
		}
		if (!pos && result < INT_MIN) {
			return INT_MIN;
		}
		return result;
	}
};