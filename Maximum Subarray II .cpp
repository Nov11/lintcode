class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer denotes the sum of max two non-overlapping subarrays
	*/
	int maxTwoSubArrays(vector<int> nums) {
		// write your code here
		if (nums.size() < 2) { return 0; }
		vector<int> v(nums.size());
		int maxVal = nums[0];
		int acc = maxVal;
		v[0] = maxVal;
		for (int i = 1; i < nums.size(); i++) {
			acc = max(acc + nums[i], nums[i]);
			// maxVal = max(maxVal, acc);
			// v[i] = maxVal;
			v[i] = max(v[i - 1], acc);
		}

		vector<int> rv(nums.size());
		maxVal = nums.back();
		acc = maxVal;
		rv.back() = maxVal;
		for (int i = nums.size() - 2; i >= 0; i--) {
			// maxVal = max(maxVal, nums[i] - minVal);
			// rv[i] = maxVal;
			// minVal = min(minVal, nums[i]);
			acc = max(acc + nums[i], nums[i]);
			rv[i] = max(rv[i + 1], acc);
		}

		int result = INT_MIN;
		for (int i = 0; i + 1< nums.size(); i++) {
			result = max(result, v[i] + rv[i + 1]);
		}

		return result;
	}
};