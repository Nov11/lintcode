class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int result = 0;
        // if(num < 0){result ++; num &= 0x7fffffff;}
        unsigned n = num;
        while(n){
            result ++;
            n &= n - 1;
        }
        
        return result;
    }
};