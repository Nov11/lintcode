class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        long long mask = 1LL << (j - i + 1);
        mask -= 1;
        mask <<= i;
        mask = ~mask;
        n &= mask;
        m <<= i;
        return n ^ m;
    }
};