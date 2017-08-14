class Solution {
public:
    
    /*
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string s) {
        // write your code here
        stack<char> stk;
        for(auto item : s){
            if(item == '(' || item == '{' || item == '['){
                stk.push(item);
            }else{
                if(s.empty()){return false;}
                char c = stk.top();
                stk.pop();
                if(item == ')' && c != '('){return false;}
                if(item == '}' && c != '{'){return false;}
                if(item == ']' && c != '['){return false;}
            }
        }
        
        return stk.empty();
    }
};