class Solution {
public:
	/**
	* @param numCourses a total of n courses
	* @param prerequisites a list of prerequisite pairs
	* @return the course order
	*/
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		// Write your code here
		unordered_map<int, int> hash;
		unordered_map<int, vector<int>> connect;

		for (int i = 0; i < numCourses; i++) {
			hash[i] = 0;
		}

		for (auto item : prerequisites) {
			hash[item.first] ++;
			connect[item.second].push_back(item.first);
		}

		vector<int> result;
		vector<int> zeros;
		for (auto item : hash) {
			if (item.second == 0) {
				zeros.push_back(item.first);
			}
		}
		int cnt = 0;

		while (!zeros.empty()) {
			vector<int> next;
			for (auto item : zeros) {
				for (auto dest : connect[item]) {
					hash[dest]--;
					if (hash[dest] == 0) {
						next.push_back(dest);
					}
				}
			}
			cnt += zeros.size();
			result.insert(result.end(), zeros.begin(), zeros.end());
			swap(next, zeros);
		}

		if (cnt == numCourses) {
			return result;
		}
		return {};
	}
};