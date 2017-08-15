class Solution {
    int h(int height, int k){
        if(height == 1){return k - 1;}
        return pow(k - 1, height - 1) * k;
    }
public:
    
    /*
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // write your code here
        if(n == 1){return k;}
        if(n == 2){return k * k;}
        int p3 = k;
        int p2 = k * k;
        for(int i = 3; i <= n; i++){
            int p1 = p2 * (k - 1) + p3 * (k - 1);
            p3 = p2;
            p2 = p1;
        }
        
        return p2;
    }
};