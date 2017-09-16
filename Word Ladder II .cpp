class Solution {
	void dfs(vector<vector<string>>& result, unordered_map<string, vector<string>>& hash, string& end, vector<string>& path) {
		vector<string> v = hash[end];
		if (v.empty()) {
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
			return;
		}
		for (auto item : v) {
			path.push_back(item);
			dfs(result, hash, item, path);
			path.pop_back();
		}
	}
public:
	/*
	* @param start: a string
	* @param end: a string
	* @param dict: a set of string
	* @return: a list of lists of string
	*/
	vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
		// write your code here
		dict.erase(start);
		if (dict.empty() || (*dict.begin()).size() != start.size() || start.size() != end.size()) {
			return {};
		}

		dict.insert(end);

		unordered_map<string, vector<string>> hash;
		hash[start] = {};
		set<string> cur{ start };

		while (!cur.empty()) {
			set<string> next;
			bool lastRound = false;
			for (auto item : cur) {
				for (int i = 0; i < item.size(); i++) {
					for (char c = 'a'; c <= 'z'; c++) {
						if (c == item[i]) { continue; }
						string tmp = item;
						tmp[i] = c;

						if (tmp == end) { lastRound = true; }
						if (dict.find(tmp) == dict.end()) { continue; }
						hash[tmp].push_back(item);
						next.insert(tmp);
					}
				}
			}
			if (lastRound) {
				break;
			}
			for (auto item : next) {
				dict.erase(item);
			}

			swap(next, cur);
		}

		vector<vector<string>> result;
		vector<string> path{ end };
		dfs(result, hash, end, path);

		return result;
	}
};