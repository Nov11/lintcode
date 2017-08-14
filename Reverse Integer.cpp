class Solution {
public:
    
    /*
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    int reverseInteger(int n) {
        // write your code here
        bool pos = n >= 0;
        long long in = n;
        if(!pos){in *= -1;}
        
        long long r = 0;
        while(in){
            r *= 10;
            r += in % 10;
            in /= 10;
        }
        
        if(!pos){r *= -1;}
        if(r > INT_MAX || r < INT_MIN){return 0;}
        return r;
    }
};