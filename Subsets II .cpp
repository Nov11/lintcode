class Solution {
	void work(vector<vector<int>>& result, vector<int>& path, map<int, int>::iterator i, map<int, int>::iterator e) {
		if (i == e) { result.push_back(path); return; }
		int val = i->first;
		auto next = i;
		next++;
		work(result, path, next, e);
		for (int j = 1; j <= i->second; j++) {
			path.push_back(val);
			work(result, path, next, e);
		}
		for (int j = 1; j <= i->second; j++) {
			path.pop_back();
		}
	}
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > subsetsWithDup(const vector<int> &S) {
		// write your code here
		map<int, int> hash;
		for (auto item : S) { hash[item]++; }
		vector<vector<int>> result{ };

		vector<int> path;
		work(result, path, hash.begin(), hash.end());
		return result;
	}
};



class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > subsetsWithDup(const vector<int> &S) {
		// write your code here
		vector<int> v(S);
		vector<vector<int>> result{ {} };
		if (S.empty()) { return result; };
		sort(v.begin(), v.end());
		result.push_back({ v[0] });
		int e = 1;
		for (int i = 1; i < S.size(); i++) {
			int len = result.size();
			int j = 0;
			if (v[i] == v[i - 1]) {
				j = e;
			}
			for (; j < len; j++) {
				result.emplace_back(result[j].begin(), result[j].end());
				result.back().push_back(v[i]);
			}
			e = len;
		}

		return result;
	}
};