class Solution {
	bool work(const string& s, int si, const string& p, int pi) {
		if (si == s.size()) {
			for (int i = pi; i < p.size(); i++) {
				if (p[i] != '*') {
					return false;
				}
			}
			return true;
		}

		if (pi == p.size()) {
			return false;
		}

		if (p[pi] == '?') {
			return work(s, si + 1, p, pi + 1);
		}
		else if (p[pi] == '*') {
			//for (int i = 0; i + si <= s.size(); i++) {
			//	if (work(s, si + i, p, pi + 1)) {
			//		return true;
			//	}
			//}
			//return false;
			if (pi + 1 == p.size()) {
				return true;
			}
			string toMatch;
			for (int i = pi + 1; i < p.size(); i++) {
				if (p[i] == '*') {
					break;
				}
				toMatch.push_back(p[i]);
			}

			bool match = false;
			int i = 0;
			for (; i + si + toMatch.size() <= s.size(); i++) {
				//s [si+i, si + i + tomatch.size()) == tomatch[0, end)
				match = true;
				for (int iter1 = si + i, iter2 = 0; iter2 < toMatch.size(); iter1++, iter2++) {
					if (s[iter1] != toMatch[iter2] && toMatch[iter2] != '?') {
						match = false;
						break;
					}
				}
				if (match) {
					break;
				}
			}
			if (!match) {
				return false;
			}
			return work(s, si + i + toMatch.size(), p, pi + toMatch.size() + 1);
		}

		if (s[si] != p[pi]) {
			return false;
		}
		return work(s, si + 1, p, pi + 1);
	}
public:
	/*
	* @param s: A string
	* @param p: A string includes "?" and "*"
	* @return: is Match?
	*/
	bool isMatch(string &s, string &p) {
		// write your code here
		string pp;
		for (auto item : p) {
			if (item == '*' && !pp.empty() && pp.back() == '*') {
				continue;
			}
			pp.push_back(item);
		}
		return work(s, 0, pp, 0);
	}
};