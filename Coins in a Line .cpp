class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        if(n == 0){return false;}
        if(n == 1 || n == 2){return true;}
        bool pp = true;
        bool p = true;
        for(int i = 3; i <= n; i++){
            bool peerWin = p && pp;
            pp = p;
            p = !peerWin;
        }
        
        return p;
    }
};