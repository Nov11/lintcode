class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        if(n <= 0){return {};}
        
        vector<vector<int>> result(n, vector<int>(n));
        int number = 1;
        for(int i = 0; i < (n + 1) / 2; i++){
            for(int k = i; k < n - i; k++){
                result[i][k] = number++;
            }
            for(int l = i + 1; l < n - i; l++){
                result[l][n - i - 1] = number++;
            }
            if(i == n - i - 1){break;}
            for(int k = n - i - 1 - 1; k >= i; k--){
                result[n - i- 1][k] = number++;
            }
            for(int l = n - i - 1 - 1; l > i; l--){
                result[l][i] = number++;
            }
        }
        
        return result;
    }
};