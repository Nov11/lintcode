class Solution {
    int m;
    int n;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};
    bool valid(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    bool work(vector<vector<bool>>& mark, vector<vector<char> > &board, string& word, int idx, int xi, int yi){
        if(idx >= word.size()){return true;}
        char c = word[idx];
        
        for(int i = 0; i < 4; i++){
            int x = xi + row[i];
            int y = yi + col[i];
            if(valid(x, y) && mark[x][y] == false && board[x][y] == c){
                mark[x][y] = true;
                bool ret = work(mark, board, word, idx + 1, x, y);
                if(ret){return true;}
                mark[x][y] = false;
            }
        }
        
        return false;
    }
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        if(word.empty()){return true;}
        m = board.size();
        if(m == 0){return false;}
        n = board[0].size();
        if(n == 0){return false;}
        
        vector<vector<bool>> mark(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    mark[i][j] = true;
                    if(work(mark, board, word, 1, i, j)){
                        return true;
                    }
                    mark[i][j] = false;
                }
            }
        }
        
        return false;
    }
};