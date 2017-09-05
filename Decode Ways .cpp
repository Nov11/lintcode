class Solution {
    int value(string& s, int idx){
        return (s[idx - 1] - '0') * 10 + (s[idx] - '0');
    }
public:
    /*
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        int len = s.size();
        if(len == 0){return 0;}
        if(s[0] == '0'){return 0;}
        if(len == 1){return 1;}
        
        vector<int> dp(len);
        dp[0] = 1;
        int tmp = value(s, 1);
        if(tmp > 26){dp[1] = 1;}
        else if(tmp == 10 || tmp == 20){dp[1] = 1;}
        else{dp[1] = 2;}
        
        for(int i = 2; i < len; i++){
            int v = value(s, i);
            if(v <= 26 && v >= 10){dp[i] += dp[i - 2];}
            if(s[i] >= '1' && s[i] <= '9'){dp[i] += dp[i - 1];}
        }
        
        return dp[len - 1];
    }
};