class Solution {
public:
	/*
	* @param : duration and close day of each course
	* @return: the maximal number of courses that can be taken
	*/
	int scheduleCourse(vector<vector<int>> &courses) {
		// write your code here
		priority_queue<int> q;
		sort(courses.begin(), courses.end()
			, [](const vector<int>& a, const vector<int>& b) {
			if (a[1] == b[1]) {
				return a[0] < b[0];
			}
			return a[1] < b[1];
		});

		int e = 0;
		for (int i = 0; i < courses.size(); i++) {
			auto& item = courses[i];
			if (item[0] > item[1]) { continue; }
			if (e + item[0] <= item[1]) {
				q.push(item[0]);
				e += item[0];
			}
			else {
				if (q.top() > item[0]) {
					e -= q.top();
					e += item[0];
					q.pop();
					q.push(item[0]);
				}
				else {
					//ignore this course and following ones with same end time
					for (int j = i + 1; j < courses.size(); j++) {
						if (courses[j][1] == item[1]) {
							i = j;
						}
						else {
							break;
						}
					}
				}
			}
		}

		return q.size();
	}
};