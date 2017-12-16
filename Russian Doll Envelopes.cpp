class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // write your code here
        // sort(envelopes.begin(), envelopes.end());
        // vector<int> dp(envelopes.size());
        
        // int result = 0;
        // for(int i =0; i < envelopes.size(); i++){
        //     pair<int, int>&cur = envelopes[i];
        //     int tmp = 1;
        //     for(int j = i - 1; j >= 0; j--){
        //         pair<int,int>& p = envelopes[j];
        //         if(p.first < cur.first && p.second < cur.second){
        //             tmp = max(tmp, 1 + dp[j]);
        //         }
        //     }
        //     dp[i] = tmp;
        //     result = max(result, tmp);
        // }
        // return result;
        
        //not my origination
        sort(envelopes.begin(), envelopes.end()
        , [](const pair<int,int>& p1, const pair<int,int>& p2){
            if(p1.first == p2.first){return p1.second > p2.second;}
            return p1.first < p2.first;
        });
        
        vector<int> dp;
        for(auto& item : envelopes){
            int height = item.second;
            auto iter = lower_bound(dp.begin(), dp.end(), height);
            if(iter == dp.end()){
                dp.push_back(height);
            }else{
                *iter = height;
            }
        }
        return dp.size();
    }
    
};
