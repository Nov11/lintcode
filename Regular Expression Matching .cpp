class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string s, string p) {
        // write your code here
        if(p.empty()){
            return s.empty();
        }
        
        if(p.size() == 1){
            return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
        }
        
        if(p[1] != '*'){
            return s.size() >= 1 && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        
        if(isMatch(s, p.substr(2))){
            return true;
        }
        
        for(int i = 0; i < s.size() && (s[i] == p[0] || p[0] == '.'); i++){
            if(isMatch(s.substr(i + 1), p.substr(2))){
                return true;
            }
        }
        return false;
    }
};
