class Solution {
public:
    /*
     * @param : An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> A) {
        // write your code here
        //increaing 
        if(A.empty()){return 0;}
        
        int result = 1;
        int b = 0;
        int e = 1;
        for(; e < A.size(); e++){
            if(A[e] <= A[e - 1]){
                result = max(result, e - b);
                b = e;
            }
        }
        result = max(result, e - b);
        
        b = A.size() - 1;
        e = b - 1;
        for(; e >= 0; e--){
            if(A[e] <= A[e + 1]){
                result = max(result, b - e);
                b = e;
            }
        }
        result = max(result, b - e);
        
        return result;
    }
};