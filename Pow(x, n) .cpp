class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if(n < 0){return 1 / myPow(x, -1 * n);}
        
        if(n == 0){return 1;}
        if(n == 1){return x;}
        
        double partial = myPow(x, n / 2);
        if(n % 2 == 1){
            return partial * partial * x;
        }
        return partial * partial;
    }
};