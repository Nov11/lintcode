class Solution {
    void work(vector<vector<bool>>& grid, int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]){return;}
        grid[x][y] = false;
        work(grid, x + 1, y);
        work(grid, x - 1, y);
        work(grid, x, y + 1);
        work(grid, x, y - 1);
    }
    int m;
    int n;
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        m = grid.size();
        if(m == 0){return 0;}
        n = grid[0].size();
        if(n == 0){return 0;}
        
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == true){
                    result++;
                    work(grid, i, j);
                }
            }
        }
        
        return result;
    }
};