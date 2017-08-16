class Solution {
    bool work(string::iterator i1, string::iterator e1, string::iterator i2, string::iterator e2,
    string::iterator i3, string::iterator e3){
        if(i3 == e3){return true;}
        
        bool ret = false;
        if(i1 != e1){
            if(*i1 == *i3){
                ret = work(i1 + 1, e1, i2, e2, i3 + 1, e3);
            }
        }
        
        if(ret){return ret;}
        
        if(i2 != e2){
            if(*i2 == *i3){
                ret = work(i1, e1, i2 + 1, e2, i3 + 1, e3); 
            }
        }
        
        return ret;
    }
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if(s1.size() + s2.size() != s3.size()){return false;}
        return work(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin(), s3.end());
    }
};