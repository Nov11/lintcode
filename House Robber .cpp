class Solution {
public:
    /*
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here
        int len = A.size();
        if(len == 0){
            return 0;
        }
        if(len == 1){
            return A[0];
        }
        if(len == 2){
            return A[0] < A[1] ? A[1] : A[0];
        }
        
        // vector<long long> dp(len);
        // dp[0] = A[0];
        // dp[1] = max(A[1], A[0]);
        // for(int i = 2; i < len; i++){
        //     dp[i] = max(dp[i - 2] + A[i], dp[i - 1]);
        // }
        
        // return dp[len -1];
        long long pp = A[0];
        long long p = max(A[0], A[1]);
        long long cur = p;
        for(int i = 2; i < len; i++){
            cur = max(pp + A[i], p);
            pp = p;
            p = cur;
        }
        return cur;
    }
};