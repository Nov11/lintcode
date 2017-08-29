class Solution {
public:
    /*
     * @param matrix: A lsit of lists of integers
     * @return: 
     */
    void setZeroes(vector<vector<int>>& matrix) {
        // write your code here
        int m = matrix.size();
        if(m == 0){return;}
        int n = matrix[0].size();
        if(n == 0){return;}
        bool row = false;
        for(auto item : matrix[0]){
            if(item == 0){row = true;break;}
        }
        bool col = false;
        for(int i = 0; i < m; i ++){
            if(matrix[i][0] == 0){col = true;break;}
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(row){
            for(auto& item : matrix[0]){item = 0;}
        }
        
        if(col){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};