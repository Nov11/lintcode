class Solution {
public:
	/**
	* @param intervals: interval list.
	* @return: A new interval list.
	*/
	vector<Interval> merge(vector<Interval> &intervals) {
		// write your code here
		if (intervals.size() <= 1) { return intervals; }
		sort(intervals.begin(), intervals.end(), [](const Interval& v1, const Interval& v2) {
			if (v1.start < v2.start) { return true; }
			if (v1.start == v2.start && v1.end < v2.end) { return true; }
			return false;
		});

		vector<Interval> result;
		Interval cur = intervals[0];
		for (int i = 1; i < intervals.size(); i++) {
			if (cur.end >= intervals[i].start) { cur.end = max(cur.end, intervals[i].end); }
			else {
				result.push_back(cur);
				cur = intervals[i];
			}
		}
		result.push_back(cur);

		return result;
	}
};