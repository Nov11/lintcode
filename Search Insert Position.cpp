class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
     int v1(vector<int>& A, int target){
        int beg = 0;
        int end = A.size();
        while(beg < end){
            int mid = beg + (end - beg) / 2;
            if(A[mid] == target){return mid;}
            else if(A[mid] > target){end = mid;}
            else {beg = mid + 1;}
        }
        return beg;
     }
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int len = A.size();
        int first = 0;
        int last = len - 1;
        while(first <= last){
            int mid = first + (last - first) / 2;
            if(A[mid] == target){return mid;}
            else if(A[mid] > target){last = mid - 1;}
            else {first = mid + 1;}
        }
        return first;
    }
};