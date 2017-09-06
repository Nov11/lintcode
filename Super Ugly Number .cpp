class Solution {
public:
    /*
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // write your code here
        vector<int> result{1};
        vector<int> idx(primes.size());
        while(result.size() < n){
            int minVal = INT_MAX;
            for(int i = 0; i < primes.size(); i++){
                minVal = min(minVal, primes[i] * result[idx[i]]);
            }
            result.push_back(minVal);
            for(int i = 0; i < primes.size(); i++){
                if(primes[i] * result[idx[i]] == minVal){
                    idx[i]++;
                }
            }
        }
        return result.back();
    }
};