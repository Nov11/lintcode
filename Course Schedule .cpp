class Solution {
public:
	/**
	* @param numCourses a total of n courses
	* @param prerequisites a list of prerequisite pairs
	* @return true if can finish all courses or false
	*/
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		// Write your code here
		unordered_map<int, int> hash;//course number -> indegree
		unordered_map<int, vector<int>> connect;

		for (int i = 0; i < numCourses; i++) {
			hash[i] = 0;
		}

		for (auto item : prerequisites) {
			hash[item.first] ++;
			connect[item.second].push_back(item.first);
		}

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
				cnt++;
				auto linkto = connect[item];
				for (auto dest : linkto) {
					hash[dest]--;
					if (hash[dest] == 0) {
						next.push_back(dest);
					}
				}
			}
			swap(next, zeros);
		}

		return cnt == numCourses;
	}
};