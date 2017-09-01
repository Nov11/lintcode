class Solution {
public:
    /*
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int>> matrix) {
        // write your code here
        int m = matrix.size();
        if(m == 0){return {};}
        int n = matrix[0].size();
        if(n == 0){return {};}
        vector<int> result;
        for(int i = 0 ; i < (m + 1) / 2 && i < (n + 1) / 2; i++){
            for(int k = i; k < n - i; k++){
                result.push_back(matrix[i][k]);
            }
            for(int l = i + 1; l < m - i; l++){
                result.push_back(matrix[l][n - i - 1]);
            }
            if(n - i - 1 == i || m - i - 1 == i){break;}
            for(int k = n - 1 - i - 1; k >= i; k--){
                result.push_back(matrix[m - i - 1][k]);
            }
            for(int l = m - i - 1 - 1; l > i; l--){
                result.push_back(matrix[l][i]);
            }
        }
        return result;
    }
};