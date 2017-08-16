class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer indicate the value of maximum difference between two
	*          Subarrays
	*/
	int maxDiffSubArrays(vector<int> nums) {
		// write your code here
		int len = nums.size();
		if (len < 2) { return 0; }
		vector<int> vMax(len);
		vector<int> vMin(len);
		vMax[0] = nums.front();
		vMin[0] = nums.front();
		int accMax = nums.front();
		int accMin = nums.front();
		for (int i = 1; i < len; i++) {
			accMax = max(accMax + nums[i], nums[i]);
			vMax[i] = max(vMax[i - 1], accMax);
			accMin = min(accMin + nums[i], nums[i]);
			vMin[i] = min(vMin[i - 1], accMin);
		}

		vector<int> rvMax(len);
		rvMax.back() = nums.back();
		vector<int> rvMin(rvMax);
		accMax = nums.back();
		accMin = accMax;

		for (int i = len - 2; i >= 0; i--) {
			accMax = max(accMax + nums[i], nums[i]);
			rvMax[i] = max(rvMax[i + 1], accMax);
			accMin = min(accMin + nums[i], nums[i]);
			rvMin[i] = min(rvMin[i + 1], accMin);
		}

		int result = 0;

		for (int i = 0; i + 1 < len; i++) {
			int tmp = max(abs(vMax[i] - rvMin[i + 1]), abs(vMin[i] - rvMax[i + 1]));
			result = max(result, tmp);
		}

		return result;
	}
};