class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        unordered_map<char,int> h1;
        unordered_map<char, int> h2;
        for(auto item : s){
            h1[item]++;
        }
        for(auto item : t){
            h2[item]++;
        }
        
        return h1 == h2;
    }
};