class Solution {
	
	map<pair<int, int>, int> hash;
	vector<set<int>> pos{ 4 };
	const int MOD = 1000000007;
	void incre(int& v, int amount) {
		v = (v + amount) % MOD;
	}
	int work(const string& str, int b, int e) {
		if (b >= e) {
			return 0;
		}
		auto iter = hash.find(make_pair(b, e));
		if (iter != hash.end()) {
			return iter->second;
		}

		int tmp = 0;

		for (int i = 0; i < 4; i++) {
			set<int>& s = pos[i];
			auto start = s.lower_bound(b);
			if (start == s.end() || *start >= e) {
				continue;
			}
			incre(tmp, 1);
			auto last = s.lower_bound(e);

			if (last != s.begin()) {
				last--;
			}
			else {
				continue;
			}

			if (*start < *last) {
				incre(tmp, 1);
				incre(tmp, work(str, *start + 1, *last));
			}
		}
		hash[make_pair(b, e)] = tmp;
		return tmp;
	}
public:
	/**
	* @param str: a string S
	* @return: the number of different non-empty palindromic subsequences in S
	*/
	int countPalindSubseq(string &str) {
		// write your code here
		for (int i = 0; i < str.size(); i++) {
			pos[str[i] - 'a'].insert(i);
		}

		return work(str, 0, str.size());
	}
};