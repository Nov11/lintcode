class Solution {
public:
    /**
     * @param s a string
     * @return it's index
     */
    int firstUniqChar(string& s) {
        // Write your code here
        unordered_map<char, int> hash;
        for(auto item : s){hash[item] ++;}
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] == 1){return i;}
        }
        
        return -1;
    }
};