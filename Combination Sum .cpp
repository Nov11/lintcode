class Solution {
    void work(vector<vector<int>>& result, vector<int>& path, vector<int>& can, int idx, int target){
        if(target < 0){return;}
        if(target == 0){
            result.push_back(path);
            return;
        }
        
        for(int i = idx; i < can.size(); i++){
            path.push_back(can[i]);
            work(result, path, can, i, target - can[i]);
            path.pop_back();
        }
    }
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        auto iter = unique(candidates.begin(), candidates.end());
        while(iter != candidates.end()){
            candidates.pop_back();
        }
        work(result, path, candidates, 0, target);
        return result;
    }
};