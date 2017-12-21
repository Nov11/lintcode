class Solution {
public:
    /*
     * @param symb: the array of symbols
     * @param oper: the array of operators
     * @return: the number of ways
     */
    int countParenth(string &symb, string &oper) {
        // write your code here
        int m = symb.size();
        int n = oper.size();
        if(m == 0){return 0;}
        if(m == 1){
            return symb[0] == 'T';
        }
        
        vector<vector<pair<int,int>>> dp(m,vector<pair<int,int>>(m));
        
        for(int i = 0; i < m; i++){
            if(symb[i] == 'T'){
                dp[i][i].first++;
            }else{
                dp[i][i].second++;
            }
        }
        
        for(int j = 1; j < m; j++){
            for(int i = j - 1; i >= 0; i--){
                auto& v = dp[i][j];
                //symb[i..k] oper[k] symb[k+1..j]
               
                for(int k = i; k < j; k++){
                    char op = oper[k];
                    auto v1 = dp[i][k];
                    auto v2 = dp[k+1][j];
                    switch(op){
                        case '&':
                        {
                            v.first += v1.first * v2.first;
                            v.second += v1.second * v2.second + v1.first* v2.second+v1.second*v2.first;
                            break;
                        }
                        case '|':
                        {
                            v.first += v1.first * v2.second + v1.second * v2.first + v1.first * v2.first;
                            v.second += v1.second * v2.second;
                            break;
                        }
                        case '^':
                        {
                            v.first +=v1.first * v2.second+v1.second * v2.first;
                            v.second+=v1.first * v2.first + v1.second * v2.second;
                            break;
                        }
                    }
                }
            }
            
        }
        
        return dp[0][m-1].first;
    }
};
