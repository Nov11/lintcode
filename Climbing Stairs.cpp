class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n <= 0){return 1;}
        if(n == 1){return 1;}
        if(n == 2){return 2;}
        
        int pp = 1;
        int p = 2;
        for(int i = 3;  i <= n; i++){
            int tmp = pp + p;
            pp = p;
            p = tmp;
        }
        
        return p;
    }
};