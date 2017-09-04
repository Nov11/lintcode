class Solution {
    void work(vector<string>& result, string& path, int left, int right){
        if(left == 0 && right == 0){
            result.push_back(path);
            return;
        }
        
        if(left){
            path.push_back('(');
            work(result, path, left - 1, right);
            path.pop_back();
        }
        
        if(right > left){
            path.push_back(')');
            work(result, path, left, right - 1);
            path.pop_back();
        }
    }
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        if(n <= 0){return {};}
        vector<string> result;
        string path("(");
        work(result, path, n - 1, n);
        return result;
    }
};