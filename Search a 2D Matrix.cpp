class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m = matrix.size();
        if(m == 0){return false;}
        int n = matrix[0].size();
        if(n == 0){return false;}
        
        int i = 0;
        int j = n - 1;
        
        while(i < m && j >= 0){
            int val = matrix[i][j];
            if(val > target){
                j--;//or binary search
            }else if(val < target){
                i++;
            }else{
                return true;
            }
        }
        
        return false;
    }
};
