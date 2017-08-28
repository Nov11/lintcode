class Solution {
    void adjust(vector<int>& A, int i){
        int len = A.size();
        if(len <= i){return;}
        int cur = A[i];
        int rightIdx = i * 2 + 2;
        int leftIdx = i * 2 + 1;
        if(leftIdx >= len){return;}
        
        if(rightIdx < len){
            if(cur < A[leftIdx] && cur < A[rightIdx]){
                //nothing
            }else{
                int smallerIdx = A[leftIdx] < A[rightIdx] ? leftIdx : rightIdx;
                swap(A[i], A[smallerIdx]);
                adjust(A, smallerIdx);
            }
        }else{
            if(cur < A[leftIdx]){
                    //nothing
            }else{
                swap(A[i], A[leftIdx]);
                adjust(A, leftIdx);
            }
        }
    }
    
    void adj(vector<int>& A, int i){
        int len = A.size();
        while(i < len){
            int mini = i;
            if(i * 2 + 1 < len && A[i] > A[i * 2 + 1]){
                mini = i * 2 + 1;
            }
            
            if(i * 2 + 2 < len && A[mini] > A[i * 2 + 2]){
                mini = i * 2 + 2;
            }
            
            if(mini == i){
                break;
            }
            
            swap(A[i], A[mini]);
            i = mini;
        }
    }
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int len = A.size();
        for(int i = (len - 2) / 2; i >= 0; i--){
            adj(A, i);
        }
    }
};