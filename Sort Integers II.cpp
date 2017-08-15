class Solution {
    int partition(vector<int>& A, int beg, int end){
        if(beg + 1 == end){return beg;}
        
        int pivot = A[beg];
        int i = beg;
        int j = end;
        while(i < j){
            while(++i < end && A[i] < pivot);
            while(--j >= beg && A[j] > pivot);
            if(i < j){
                swap(A[i], A[j]);
            }else{
                break;
            }
        }
        
        swap(A[beg], A[j]);
        return j;
    }
    
    void sort(vector<int>& A, int beg, int end){
        if(beg >= end){return;}
        int k = partition(A, beg, end);
        sort(A, beg, k);
        sort(A, k + 1, end);
    }
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        sort(A, 0, A.size());
    }
};