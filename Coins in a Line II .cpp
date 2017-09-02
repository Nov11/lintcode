class Solution {
public:
    /*
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int len = values.size();
        if(len <= 2){return true;}
        
        vector<long long> dp(len + 1);
        dp[len] = 0;
        dp[len - 1] = values[len - 1];
        dp[len - 2] = values[len - 1] + values[len - 2];
        dp[len - 3] = values[len - 3] + values[len - 2];
        for(int i = len - 4; i >= 0; i--){
            dp[i] = max(values[i] + min(dp[i + 2], dp[i + 3]), values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]));
        }
        long long sum = accumulate(values.begin(), values.end(), 0LL);
        return dp[0] + dp[0] > sum;
    }
};