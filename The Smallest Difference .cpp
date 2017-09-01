class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        if(A.empty() || B.empty()){return 0;}
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long result = INT_MAX;
        for(auto item : A){
            auto iter = lower_bound(B.begin(), B.end(), item);
            long long diff = item;
            if(iter == B.begin()){
                diff -= *iter; 
            }else if(iter == B.end()){
                diff -= *(--iter);
            }else{
                int cur = diff - *iter;
                int prev = diff - *(--iter);
                diff = min(abs(cur), abs(prev));
            }
            
            result = min(result, abs(diff));
        }
        return result;
    }
};
