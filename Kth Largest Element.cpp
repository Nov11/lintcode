class Solution {
	int partition(vector<int>& nums, int beg, int end) {
		if (beg + 1 == end) { return nums[beg]; }
		int pivot = nums[beg];

		int i = beg;
		int j = end;
		while (true) {
			while (++i < end && nums[i] < pivot);
			while (--j >= beg && nums[j] > pivot);
			if (i < j) {
				swap(nums[i], nums[j]);
			}
			else {
				break;
			}
		}

		swap(nums[beg], nums[j]);

		return j;
	}
public:
	/*
	* param k : description of k
	* param nums : description of array and index 0 ~ n-1
	* return: description of return
	*/
	int kthLargestElement(int k, vector<int> nums) {
		// write your code here
		int beg = 0;
		int end = nums.size();
		if (k > end || k < 1) { return -1; }
		k = end - k;
		while (true) {
			int pos = partition(nums, beg, end);
			if (pos == k) { break; }
			else if (pos > k) {
				end = pos;
			}
			else {
				beg = pos + 1;
			}
		}

		return nums[k];
	}
};
