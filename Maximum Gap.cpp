class Solution {
public:
	/*
	* @param nums: an array of integers
	* @return: the maximun difference
	*/
	int maximumGap(vector<int> &nums) {
		// write your code here
		if (nums.size() < 2) { return 0; }
		int len = nums.size();
		int upper = nums[0];
		int lower = nums[0];
		unordered_map<int, int> hash;
		hash[nums[0]]++;
		for (int i = 1; i < nums.size(); i++) {
			upper = max(upper, nums[i]);
			lower = min(lower, nums[i]);
			if (++hash[nums[i]] != 1) {
				len--;
			}
		}
		if (upper <= lower || len == 1) {
			return 0;
		}
		int bucketSize = ceil((upper - lower) * 1.0 / (len - 1)) - 1;
		if (bucketSize <= 0) {
			return 1;
		}

		vector<vector<int>> bucket((upper - lower) / bucketSize + 1, vector<int>{-1, -1});//waste one vector if total can be divided

		for (auto item : nums) {
			int idx = (item - lower) / bucketSize;
			auto& ref = bucket[idx];
			if (ref[0] == -1 && ref[1] == -1) {
				ref = { item, item };
			}
			else {
				if (ref[0] == item || ref[1] == item) {
					continue;
				}
				else if (ref[0] > item) {
					ref[0] = item;
				}
				else if (ref[1] < item) {
					ref[1] = item;
				}
				else {
					//nothing
				}
			}
		}

		int result = -1;
		int last = bucket[0][1];
		for (int i = 1; i < bucket.size(); i++) {
			if (bucket[i][0] == -1) { continue; }
			if (last == -1) {
				last = bucket[i][1];
				continue;
			}

			result = max(result, bucket[i][0] - last);
			last = bucket[i][1];
		}

		return result;
	}
};