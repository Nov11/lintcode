class Solution {
	string binaryAdd(const string& a, const string& b) {
		//a and b is binary form and are not negative number
		if (a.empty() || b.empty()) { return "0"; }
		if (a == "0") { return b; }
		if (b == "0") { return a; }

		string result;
		auto ia = a.rbegin();
		auto ib = b.rbegin();
		int carry = 0;
		while (ia != a.rend() || ib != b.rend()) {
			int va = ia != a.rend() ? *ia++ - '0' : 0;
			int vb = ib != b.rend() ? *ib++ - '0' : 0;
			int sum = va + vb + carry;
			carry = sum / 2;
			result.push_back(sum % 2 + '0');
		}
		if (carry) {
			result.push_back('1');
		}
		reverse(result.begin(), result.end());
		return result;
	}

	string binaryMul10(const string& s) {
		if (s.empty()) {
			return "0";
		}
		if (s == "0") {
			return "0";
		}
		// times 8
		string result = s + "000";
		result = binaryAdd(result, binaryAdd(s, s));
		return result;
	}
	map<int, string> m{
		{ 0,"0" },
		{ 1,"1" },
		{ 2,"10" },
		{ 3,"11" },
		{ 4,"100" },
		{ 5,"101" },
		{ 6,"110" },
		{ 7,"111" },
		{ 8,"1000" },
		{ 9,"1001" }
	};
	string integerToBinary(const string& s) {
		if (s.empty()) { return "0"; }// for .XXX  integer is "", return 0 here
		if (s.size() == 1) { return m[s[0] - '0']; }
		string result{ "0" };

		for (auto iter = s.begin(); iter != s.end(); iter++) {
			result = binaryMul10(result);
			char c = *iter;
			int v = c - '0';
			result = binaryAdd(result, m[v]);
		}

		return result;
	}
	string tenBaseDoubleValue(const string& s) {
		if (s.empty()) { return ""; }
		int carry = 0;
		string result;
		for (auto riter = s.rbegin(); riter != s.rend(); riter++) {
			int sum = carry + (*riter - '0') * 2;
			carry = sum / 10;
			result.push_back(sum % 10 + '0');
		}
		if (carry) {
			result.push_back('1');
		}

		reverse(result.begin(), result.end());

		return result;
	}

	bool isZero(const string& s) {
		if (s.empty()) {
			return false;
		}

		for (auto item : s) {
			if (item != '0') {
				return false;
			}
		}

		return true;
	}
	string decimalToBinary(string s) {
		if (s.empty()) { return ""; }
		if (isZero(s)) { return ""; }
		set<string> dup;
		string result;
		for (int i = 0; i < 32; i++) {
			if (dup.find(s) != dup.end()) { break; }
			dup.insert(s);

			string ret = tenBaseDoubleValue(s);
			if (ret.size() > s.size()) {
				result.push_back('1');
				s = ret.substr(1);
			}
			else {
				result.push_back('0');
				s = ret;
			}

			if (isZero(s)) {
				if (isZero(result)) {
					return "";
				}
				return result;
			}
		}
		return "ERROR";
	}
public:
	/**
	*@param n: Given a decimal number that is passed in as a string
	*@return: A string
	*/
	string binaryRepresentation(string n) {
		// wirte your code here
		if (n.empty()) { return n; }
		bool neg = false;
		if (!isdigit(n[0])) {
			if (n[0] == '-') {
				neg = true;
			}
			n = n.substr(1);
		}

		auto dot = n.find('.', 0);
		string integer;
		string decimal;
		if (dot == string::npos) {
			integer = n;
		}
		else {
			integer = n.substr(0, dot);
			decimal = n.substr(dot + 1);
		}

		string result;
		if (neg) {
			result.push_back('-');
		}
		string intRet = integerToBinary(integer);
		result.append(intRet);
		if (!decimal.empty()) {
			
			string ret = decimalToBinary(decimal);
			if (ret == "ERROR") {
				return ret;
			}
			else if (!ret.empty()) {
				result.push_back('.');
				result.append(ret);
			}
		}

		return result;
	}
};