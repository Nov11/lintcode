class Solution {
public:
	/*
	* @param : Given an integers array A
	* @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
	*/
	//this is lame
	vector<long long> productExcludeItself(vector<int> nums) {
		// write your code here
		vector<long long> result;
		for (int i = 0; i < nums.size(); i++) {
			long long product = 1;
			for (int j = 0; j < nums.size(); j++) {
				if (j == i) { continue; }
				product *= nums[j];
			}
			result.push_back(product);
		}

		return result;
	}
};