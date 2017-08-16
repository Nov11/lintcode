class Solution {
public:
	/**
	* @param source: A string
	* @param target: A string
	* @return: A string denote the minimum window
	*          Return "" if there is no such a string
	*/
	string minWindow(string &source, string &target) {
		// write your code here
		unordered_map<char, int> hash;
		int cnt = 0;
		for (auto item : target) { hash[item]++; cnt++; }
		string result;
		int len = INT_MAX;
		queue<pair<char, int>> q;
		for (int i = 0; i < source.size(); i++) {
			char c = source[i];
			if (hash.find(c) == hash.end()) { continue; }
			q.push(make_pair(c, i));

			if (hash[c] > 0) { cnt--; }
			hash[c]--;
			while (cnt == 0) {
				auto p = q.front();
				if (len > i - p.second + 1) {
					len = i - p.second + 1;
					result = source.substr(p.second, len);
				}
				if (hash[p.first] == 0) {
					hash[p.first]++;
					cnt++;
					q.pop();
					continue;
				}
				hash[p.first]++;
				q.pop();
			}
		}

		return len == INT_MAX ? "" : result;
	}
};