class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> A) {
        // write your code here
        int farthest = 0;
        int len = A.size();
        for(int i = 0; i < len && i <= farthest; i++){
            farthest = max(farthest, i + A[i]);   
        }
        
        return farthest >= len - 1? true : false;
    }
};