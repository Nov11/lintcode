class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        // int beg = 0;
        // int end = A.size();
        // while(beg < end){
        //     int mid = beg + (end - beg) / 2;
        //     if(A[mid] == target){return mid;}
        //     else if(A[mid] > target){end = mid;}
        //     else{beg = mid + 1;}
        // }
        
        // return -1;
        
        int len = A.size();
        int head = 0;
        int tail = len - 1;
        
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            if(A[mid] == target){return mid;}
            else if(A[mid] > target){tail = mid - 1;}
            else{head = mid + 1;}
        }
        
        return -1;
    }
};