class Solution {
public:
    /*
     * @param matrix: a lists of integers
     * @return: 
     */
    void rotate(vector<vector<int>>& matrix) {
        // write your code here
        int n = matrix.size();
        for(auto& item : matrix){
            for(int i = 0; i < n / 2; i++){
                swap(item[i], item[n - i - 1]);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
    }
};