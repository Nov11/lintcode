class Solution {
    void work(string& s, int idx, vector<vector<string>>& result, vector<string>& path, vector<vector<bool>>& dp){
        if(idx == s.size()){result.push_back(path);return;}
        
        for(int i = idx; i < s.size(); i++){
            if(dp[idx + 1][i + 1]){
                path.push_back(s.substr(idx, i - idx + 1));
                work(s, i + 1, result, path, dp);
                path.pop_back();
            }
        }
    }
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        int len = s.size();
        
        vector<vector<bool>> dp(len + 1, vector<bool>(len + 1));
        for(int j = 1; j <= len; j++){
            dp[j][j] = true;
            for(int i = j - 1; i >= 1; i--){
                if(s[i - 1] == s[j - 1] && (i == j - 1 || dp[i + 1][j - 1])){
                    dp[i][j] = true;
                }
            }
        }
        
        vector<vector<string>> result;
        vector<string> path;
        work(s, 0, result, path, dp);
        return result;
    }
};