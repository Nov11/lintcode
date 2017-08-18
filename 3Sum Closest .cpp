class Solution {
	int bs(vector<int>& nums, int beg, int end, int target) {
		if (beg >= end) { return -1; }
		while (beg < end) {
			int mid = beg + (end - beg) / 2;
			if (nums[mid] == target) { return mid; }
			else if (nums[mid] > target) { end = mid; }
			else { beg = mid + 1; }
		}
		return beg;
	}
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @param target: An integer
	* @return: return the sum of the three integers, the sum closest target.
	*/
	int threeSumClosest(vector<int> nums, int target) {
		// write your code here
		int len = nums.size();
		if (len < 3) { return 0; }

		int result;
		int diff = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 2; i++) {
			if (i != 0 && nums[i] == nums[i - 1]) { continue; }
			for (int j = i + 1; j < len - 1; j++) {
				if (j != i + 1 && nums[j] == nums[j - 1]) { continue; }
				int t = target - nums[i] - nums[j];
				int r = bs(nums, j + 1, len, t);
				if (r >= j + 1 && r < len) {
					if (diff > abs(t - nums[r])) {
						diff = abs(t - nums[r]);
						result = nums[i] + nums[j] + nums[r];
					}
				}
				r--;
				if (r >= j + 1 && r < len) {
					if (diff > abs(t - nums[r])) {
						diff = abs(t - nums[r]);
						result = nums[i] + nums[j] + nums[r];
					}
				}
				if (diff == 0) { return result; }
			}
		}
		return result;
	}
};