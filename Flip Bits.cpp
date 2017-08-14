class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int tmp = a ^ b;
        int result = 0;
        while(tmp){
            tmp &= tmp - 1;
            result ++;
        }
        
        return result;
    }
};