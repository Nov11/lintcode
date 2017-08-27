class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string s, unordered_set<string> dict) {
        // write your code here
        
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        
        size_t maxWordLen = 0;
        for(auto item : dict){
            maxWordLen = max(maxWordLen, item.size());
        }
        
        for(int i = 1; i < dp.size(); i++){
            for(int j = i - 1; j >= 0 && i - j <= maxWordLen; j--){
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};