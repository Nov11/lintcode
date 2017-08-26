class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int len = A.size();
        
        if(len == 0 || m == 0){return 0;}
        
        vector<int> dp(m + 1);
        
        for(int i = A[0]; i <= m; i++){
            dp[i] = A[0];
        }
        
        for(int j = 1; j < len; j++){
            int size = A[j];
            vector<int> tmp(m + 1);
            for(int i = 1; i <= m; i++){
                tmp[i] = dp[i];
                if(i >= size){
                    tmp[i] = max(dp[i - size] + size, tmp[i]);
                }
            }
            swap(tmp, dp);
        }
        
        return dp[m];
    }
};