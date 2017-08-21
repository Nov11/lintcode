class Solution {
public:
    /*
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> A, int target) {
        // write your code here
        int len = A.size();
        int i = 0;
        int j = len;
        while(i < j){
            int mid = i + (j - i) / 2;
            if(A[mid] == target){
                return true;
            }
            
            if(A[i] < A[mid]){
                if(target >= A[i] && target < A[mid]){
                    j = mid;
                }else{
                    i = mid + 1;
                }
            }else if(A[i] > A[mid]){
                if(target > A[mid] && target <= A[j - 1]){
                    i = mid + 1;
                }else{
                    j = mid;
                }
            }else{
                i++;
            }
        }
        
        return false;
    }
};