class Solution {
public:
    /*
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> prices) {
        // write your code here
        int result = 0;
        for(int i = 1; i < prices.size(); i++){
            result += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
        }
        
        return result;
    }
};