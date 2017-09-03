class Solution {
public:
    /*
     * @param n: a number
     * @return: Gray code
     */
    vector<int> grayCode(int n) {
        // write your code here
        if(n == 0){return {0};}
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        if(n == 1){return result;}
        for(int i = 2; i <= n; i++){
            int mask = 1 << (i - 1);
            int last = result.size() - 1;
            for(; last >= 0; last--){
                result.push_back(mask | result[last]);
            }
        }
        return result;
    }
};