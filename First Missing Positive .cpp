class Solution {
public:
    /*
     * @param A: An array of integers
     * @return: An integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        for(int i = 0; i < A.size(); ){
            if(A[i] <= 0 || A[i] == i + 1||A[i] >= A.size()||A[A[i] - 1] == A[i]){i++;continue;}
            swap(A[i], A[A[i] - 1]);
        }
        
        for(int i = 0; i < A.size(); i++){
            if(A[i] != i + 1){
                return i + 1;
            }
        }
        return A.size() + 1;
    }
};