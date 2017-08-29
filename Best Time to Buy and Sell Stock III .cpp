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
        
        vector<int> first(len);
        int mini = prices[0];
        for(int i = 1; i < len; i++){
            first[i] = max(first[i - 1], prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        
        vector<int> second(len);
        second[len - 1] = 0;
        int maxi = prices[len - 1];
        for(int i = len - 2; i >= 0; i--){
            second[i] = max(maxi - prices[i], second[i + 1]);
            maxi = max(maxi, prices[i]);
        }
        
        int result = max(0, first[len - 1]);
        for(int i = 0; i + 1 < len; i++){
            result = max(result, first[i] + second[i + 1]);
        }
        return result;
    }
};