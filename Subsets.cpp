class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	vector<vector<int>> result{{}};
    	sort(nums.begin(), nums.end());
    	for(auto item : nums){
    	    int len = result.size();
    	    for(int i = 0; i < len; i++){
    	        result.emplace_back(result[i].begin(), result[i].end());
    	        result.back().push_back(item);
    	    }
    	}
    	
    	return result;
    }
};