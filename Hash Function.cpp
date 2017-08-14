class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        if(key.empty()){return 0;}
        long long result = 0;
        long long  mul = 1;
        for(int i = key.size() - 1; i >= 0; i--){
            result += key[i] * mul;
            mul *= 33;
            mul %= HASH_SIZE;
            result %= HASH_SIZE;
        }
        
        return result;
    }
};