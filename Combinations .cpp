class Solution {
    vector<vector<int>> result;
    void work(vector<int>& path, int start, int cnt, int n, int k){
        if(cnt == k){result.push_back(path);return;}
        
        for(int i = start; i <= n + 1 - k + cnt; i++){
            path.push_back(i);
            work(path, i + 1, cnt + 1, n, k);
            path.pop_back();
        }
    }
public:
    /*
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        // write your code here
        vector<int> path;
        work(path, 1, 0, n, k);
        return result;
    }
};