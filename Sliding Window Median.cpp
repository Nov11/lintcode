#include <assert.h>
class Solution {
	map<int, int> mins;
	int minSize = 0;
	map<int, int> maxs;
	int maxSize = 0;

	int minTop() {
		return mins.begin()->first;
	}

	void addMin(int n) {
		mins[n]++;
		minSize++;
	}

	void addMax(int n) {
		maxs[n]++;
		maxSize++;
	}

	int maxTop() {
		return maxs.rbegin()->first;
	}

	void removeMax(int n) {
		auto iter = maxs.find(n);
		if (iter != maxs.end()) {
			iter->second--;
			if (iter->second == 0) {
				maxs.erase(iter);
			}
			maxSize--;
		}
	}

	void removeMin(int n) {
		auto iter = mins.find(n);
		if (iter != mins.end()) {
			iter->second--;
			if (iter->second == 0) {
				mins.erase(iter);
			}
			minSize--;
		}
	}
	void removeOneFromMinH() {
		assert(minSize);
		removeMin(minTop());
	}

	void removeOneFromMaxH() {
		assert(maxSize);
		removeMax(maxTop());
	}
	void add(int n) {
		assert(minSize == maxSize || minSize == maxSize + 1);
		if (mins.empty() && maxs.empty()) {
			addMin(n);
			return;
		}

		if (!mins.empty() && minTop() <= n) {
			addMin(n);
			if (minSize > maxSize + 1) {
				addMax(minTop());
				removeOneFromMinH();
			}
		}
		else {
			addMax(n);
			if (maxSize > minSize) {
				addMin(maxTop());
				removeOneFromMaxH();
			}
		}
	}
	void del(int n) {
		assert(minSize == maxSize || minSize == maxSize + 1);
		assert(!mins.empty());
		if (minTop() <= n) {
			removeMin(n);
			if (minSize < maxSize) {
				addMin(maxTop());
				removeOneFromMaxH();
			}
		}
		else {
			removeMax(n);
			if (maxSize + 1 < minSize) {
				addMax(minTop());
				removeOneFromMinH();
			}
		}
	}

	int mid() {
		assert(minSize == maxSize || minSize == maxSize + 1);
		assert(!mins.empty());
		//return minTop();
		if (minSize == maxSize + 1) {
			return minTop();
		}
		return maxTop();
	}
public:
	/*
	* @param nums: A list of integers
	* @param k: An integer
	* @return: The median of the element inside the window at each moving
	*/
	vector<int> medianSlidingWindow(vector<int> &nums, int k) {
		// write your code here
		vector<int> result;

		for (int i = 0; i < nums.size(); i++) {
		    add(nums[i]);
			if (i >= k - 1) {
				result.push_back(mid());
				del(nums[i - k + 1]);
			}
		}

		return result;
	}
};