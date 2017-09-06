class Solution {
    long long mergeSort(vector<int>& A, int beg, int end){
        if(beg + 1 >= end){return 0;}
        int mid = beg + (end - beg) / 2;
        auto left = mergeSort(A, beg, mid);
        auto right = mergeSort(A, mid, end);
        auto c = merge(A, beg, mid, end);
        return left + right + c;
    }
    long long merge(vector<int>& A, int beg, int mid, int end){
        vector<int> left;
        vector<int> right;
        for(int i = beg; i < mid; i++){
            left.push_back(A[i]);
        }
        for(int i = mid; i < end; i++){
            right.push_back(A[i]);
        }
        
        int l = 0;
        int r = 0;
        long long result = 0;
        for(int i = beg; i < end; i++){
            if(l == left.size()){
                A[i] = right[r++];
                continue;
            }
            if(r == right.size()){
                A[i] = left[l++];
                continue;
            }
            
            if(left[l] <= right[r]){
                A[i] = left[l];
                l++;
            }else{
                A[i] = right[r];
                result += left.size() - l;
                r++;
            }
        }
        
        return result;
    }
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        return mergeSort(A, 0, A.size());
    }
};