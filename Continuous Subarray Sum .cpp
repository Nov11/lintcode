class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        if(A.empty()){
            return {};
        }
        
        vector<int> result{0, 0};
        vector<int> current(result);
        int accSum = 2 * A[0];
        int maxVal = accSum;
        for(int i = 1; i < A.size(); i++){
            if(accSum + A[i] > A[i]){
                current[1] = i;
                accSum += A[i];
            }else{
                accSum = A[i];
                current = {i, i};
            }
            if(maxVal < accSum){
                maxVal = accSum;
                result = current;
            }
        }
        
        return result;
    }
};