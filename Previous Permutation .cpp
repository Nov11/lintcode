class Solution {
public:
	/**
	* @param nums: An array of integers
	* @return: An array of integers that's previous permuation
	*/
	vector<int> previousPermuation(vector<int> &nums) {
		// write your code here
		if (nums.size() <= 1) { return nums; }

		int i = nums.size() - 1;
		for (; i >= 1; i--) {
			if (nums[i] < nums[i - 1]) { break; }
		}

		if (i == 0) { reverse(nums.begin(), nums.end()); return nums; }

		int j = nums.size() - 1;
		for (; j >= i; j--) {
			if (nums[j] < nums[i - 1]) { break; }
		}

		swap(nums[i - 1], nums[j]);
		reverse(nums.begin() + i, nums.end());
		return nums;
	}
};