class Solution {
    vector<vector<int>> result;
    void work(vector<int>& path, int start, vector<int>& num, int target){
        if(target == 0){result.push_back(path);return;}
        int len = num.size();
        for(int i = start; i < len && num[i] <= target; i++){
               path.push_back(num[i]);
               work(path, i + 1, num, target - num[i]);
               path.pop_back();
               while(i + 1 < len && num[i] == num[i + 1]){i++;}
        }
    }
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        sort(num.begin(), num.end());
        vector<int> path;
        work(path, 0, num, target );
        return result;
    }
};