class Solution {
public:
    /*
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        // write your code here
        long long p1 = dividend;
        long long p2 = divisor;
        if(p2 == 0){return INT_MAX;}
        
        int positive = p1 > 0 && p2 > 0 || p1 < 0 && p2 < 0 ? 1 : -1;
        p1 = abs(p1);
        p2 = abs(p2);
        long long result = 0;
        while(p1 >= p2){
            // result++;
            // p1 -= p2;
            for(int i = 0; i < 32; i++){
                if((p2 << (i + 1)) > p1){
                    p1 -= p2 << i;
                    result += 1LL << i;
                    break;
                }
            }
        }
        result *= positive;
        if(result > INT_MAX || result < INT_MIN){
            return INT_MAX;
        }
        
        return result;
    }
};