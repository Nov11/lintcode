class Solution {
    int work(string& str, int idx, vector<bool>& memo, int cnt, int n){
        if(cnt + 1 == n && idx == str.size()){
            for(int i = 1; i <= n; i++){
                if(memo[i] == false){
                    return i;
                }
            }
        }
        
        if(idx == str.size() || cnt + 1 == n){return 0;}
        
        //one digit
        int v = str[idx] - '0';
        if(v >= 1 && v <= n && memo[v] == false){
            memo[v] = true;
            auto ret = work(str, idx + 1, memo, cnt + 1, n);
            memo[v] = false;
            if(ret != 0){return ret;}
        }
        //two digits
        if(v == 0 || idx + 1 == str.size()){return 0;}
        v *= 10;
        v += str[idx + 1] - '0';
        if(v >= 10 && v <= n && memo[v] == false){
            memo[v] = true;
            auto ret = work(str, idx + 2, memo, cnt + 1, n);
            memo[v] = false;
            if(ret){return ret;}
        }
        return 0;
    }
public:
    /*
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        // write your code here
        if(n == 1){return 1;}
        vector<bool> memo(31);
        return work(str, 0, memo, 0, n);
    }
};