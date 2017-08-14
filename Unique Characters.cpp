class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        unordered_map<char, int> hash;
        for(auto item : str){
            hash[item]++;
            if(hash[item] > 1){return false;}
        }
        return true;
    }
};