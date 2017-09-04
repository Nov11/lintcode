class Solution {
    unordered_map<char, vector<char>> hash{
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };
    void work(vector<string> & result, string& path, string& digits, int idx){
        if(idx == digits.size()){result.push_back(path);return;}
        
        for(auto item : hash[digits[idx]]){
            path.push_back(item);
            work(result, path, digits, idx+1);
            path.pop_back();
        }
    }
public:
    /*
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        if(digits.empty()){return {};}
        vector<string> result;
        string path;
        work(result, path, digits, 0);
        return result;
    }
};