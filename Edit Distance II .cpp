class Solution {
    bool eq(string& s, int begs, string& t, int begt){
        if(s.size() - begs != t.size() - begt){return false;}
        
        for(int i = s.size() - begs - 1; i >= 0; i--){
            if(s[begs + i] != t[begt + i]){
                return false;
            }
        }
        
        return true;
    }
public:
    /*
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        int ls = s.size();
        int lt = t.size();
        if(abs(ls - lt) > 1){return false;}
        
        for(int i = 0; i < min(ls, lt); i++){
            if(s[i] != t[i]){
                if(ls == lt){
                    return eq(s, i + 1, t, i + 1);
                }else{
                    if(ls < lt){
                        swap(s, t);
                    }
                    return eq(s, i + 1, t, i);
                }
            }
        }
        return abs(ls - lt) == 1;
    }
};