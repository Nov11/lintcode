class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int len = A.size();
        int i = 0;
        int j = len;
        
        while(i < j){
            if(A[i] < A[j - 1]){
                while(i < j){
                    int mid = i + (j - i) / 2;
                    if(A[mid] == target){return mid;}
                    else if(A[mid] > target){j = mid;}
                    else{i = mid + 1;}
                }
                return -1;
            }
            
            int mid = i + (j - i) / 2;
            if(A[mid] == target){return mid;}
            if(A[mid] >= A[i]){
                if(target > A[mid]){
                    i = mid + 1;
                }else if(target >= A[i]){
                    j = mid;
                }else{
                    i = mid + 1;
                }
            }else{
                if(target > A[mid] && target <= A[j - 1]){
                    i = mid + 1;
                }else{
                    j = mid;
                }
            }
        }
        
        return -1;
    }
};