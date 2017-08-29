class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n == 1){return a % b;}
        if(n == 0){return 1 % b;}
        long long ret = fastPower(a, b, n / 2);
        if(n % 2 == 1){
            return int(ret * ((ret * (a % b)) % b) % b);
        }
        return int(ret * ret % b);
        // ret = ret * ret % b;
        // if(n % 2 == 1){
        //     ret *= a % b;
        //     ret %= b;
        // }
        // return ret;
    }
};