class Solution {
public:
    /*
     * @param gas: An array of integers
     * @param cost: An array of integers
     * @return: An integer
     */
    int canCompleteCircuitOld(vector<int> gas, vector<int> cost) {
        // write your code here
        int len = gas.size();
        for(int i = 0; i < len; i++){
            if(gas[i] >= cost[i]){
                int gasLeft = gas[i] - cost[i];
                int j = (i + 1) % len;
                for(; j != i; j = (j + 1) % len){
                    if(gasLeft + gas[j] < cost[j]){break;}
                    else{gasLeft = gasLeft + gas[j] - cost[j];}
                }
                if(j == i){
                    return j;
                }
            }
        }
        return - 1;
    }
    //ref : https://leetcodenotes.wordpress.com/2013/11/21/leetcode-gas-station-%E8%BD%AC%E5%9C%88%E7%9A%84%E5%8A%A0%E6%B2%B9%E7%AB%99%E7%9C%8B%E8%83%BD%E4%B8%8D%E8%83%BD%E8%B5%B0%E4%B8%80%E5%9C%88/
    int canCompleteCircuit(vector<int> gas, vector<int> cost) {
        int len = gas.size();
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += gas[i] - cost[i];
        }
        if(sum < 0){return -1;}
        
        int gasLeft = 0;
        int result = 0;
        for(int i = 0; i < len; i++){
            int diff = gas[i] - cost[i];
            gasLeft += diff;
            if(gasLeft < 0){
                result = i + 1;
                gasLeft = 0;
            }
        }
        
        return result;
    }
};