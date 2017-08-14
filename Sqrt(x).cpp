class Solution {
    double iter(double param, int c){
        return param - (param * param - c) / 2 / param;
    }
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        double init = 1;
        double r = iter(init, x);
        while(abs(r - init) > 0.01){
            init = r;
            r = iter(init, x);
        }
        return r;
    }
};