class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if the characters in s
     * can be replaced to get t or false
     */
    bool isIsomorphic(string& s, string& t) {
        // Write your code here
        if(s.size() != t.size()){return false;}
        
        unordered_map<char, char> hash;
        set<char> ss;
        for(int i = 0; i < s.size(); i++){
            if(hash.find(s[i]) == hash.end()){
                if(ss.find(t[i]) !=ss.end()){return false;}
                hash[s[i]] = t[i]; 
                ss.insert(t[i]);
            }
            else{
                if(hash[s[i]] != t[i]){return false;}
            }
        }
        
        return true;
    }
};