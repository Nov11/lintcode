class Solution {
    int result = 0;
    void work(int level, int n, int left, int up, int right){
        if(level == n){result++; return;}
        int mask = left;
        mask |= up;
        mask |= right;
        
        for(int i = 0; i < n; i++){
            int m = 1 << i;
            if((mask & m) == 0){
                work(level + 1, n, (left | m) << 1, up | m, (right | m) >> 1);
            }
        }
    }
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        for(int i = 0; i < n; i++){
            int mask = 1 << i;
            work(1, n, mask << 1, mask, mask >> 1);
        }
        return result;
    }
};
