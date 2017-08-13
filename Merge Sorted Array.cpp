class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        if(n == 0){return;}
        int i = m - 1;
        int j = n - 1;
        int idx = m + n - 1;
        while(i >= 0 || j >= 0){
            int va = i >= 0 ? A[i] : INT_MIN;
            int vj = j >= 0 ? B[j] : INT_MIN;
            if(va > vj){
                A[idx] = va;
                i--;
            }else{
                A[idx] = vj;
                j--;
            }
            idx--;
        }
    }
};