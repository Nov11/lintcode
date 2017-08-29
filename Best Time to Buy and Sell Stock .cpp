class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> prices) {
        // write your code here
        int len = prices.size();
        if(len <= 1){return 0;}
        
        int result = 0;
        int mini = prices[0];
        for(int i = 1; i < len; i++){
            result = max(result, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        
        return result;
    }
};