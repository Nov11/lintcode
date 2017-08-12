class Solution {
    int count(int n, int k){
        if(n == 0 && k == 0){return 1;}
        int result = 0;
        while(n){
            int digit = n % 10;
            if(digit == k){result++;}
            n /= 10;
        }
        
        return result;
    }
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int result = 0;
        for(int i = 0; i <= n; i++){
            result += count(i, k);
        }
        
        return result;
    }
};