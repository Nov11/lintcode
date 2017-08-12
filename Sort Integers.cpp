class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        int len = A.size();
        for(int i = 1; i < len; i++){
            while(i > 0 && A[i - 1] > A[i]){
                swap(A[i - 1], A[i]);
                i--;
            }
        }
    }
    
    void selection(vector<int>& A){
        int len = A.size();
        for(int i = 0; i < len; i++){
            int minIdx = i;
            for(int j = i + 1; j < len; j++){
                if(A[j] < A[minIdx]){
                    minIdx = j;
                }
            }
            swap(A[minIdx], A[i]);
        }
    }
    
    void bubble(vector<int>& A){
        int len = A.size();
        for(int i = 0; i < len - 1; i++){
            bool flag = false;
            for(int j = 1; j < len - i; j++){
                if(A[j - 1] > A[j]){
                    swap(A[j - 1], A[j]);
                    flag = true;
                }
            }
            if(flag == false){break;}
        }
    }
};