class Solution {
public:
	/*
	* @param intervals: Sorted interval list.
	* @param newInterval: new interval.
	* @return: A new interval list.
	*/

	vector<Interval> insert(vector<Interval> intervals, Interval newInterval) {
		// write your code here
		int len = intervals.size();
		if (len == 0) { intervals.push_back(newInterval); return intervals; }

		int i = 0;
		for (; i < len; i++) {
			if (intervals[i].start > newInterval.end) { break; }
		}

		if (i == 0) { intervals.insert(intervals.begin(), newInterval); return intervals; }
		if (intervals[i - 1].end < newInterval.start) { intervals.insert(intervals.begin() + i, newInterval); return intervals; }
		auto iter = intervals.begin() + i - 1;
		iter->end = max(iter->end, newInterval.end);
		iter->start = min(iter->start, newInterval.start);
		while (iter != intervals.begin()) {
			auto prev = iter - 1;
			if (prev->end < iter->start) { break; }
			else {
				iter->start = min(iter->start, prev->start);
				iter = intervals.erase(prev);
			}
		}

		return intervals;
	}

};