class Solution {
public:
    /*
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> &tokens) {
        // write your code here
        if(tokens.empty()){return 0;}
        stack<int> s;
        for(auto item : tokens){
            if(item.size() == 1 
            && (item[0] == '+' || item[0] == '-' || item[0] == '/' || item[0] == '*')){
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                switch(item[0]){
                    case '+':
                    s.push(a+b);break;
                    case '-':
                    s.push(a-b);break;
                    case '/':
                    s.push(a/b);break;
                    case '*':
                    s.push(a*b);break;
                }
            }else{
                s.push(stoi(item));
            }
        }
        return s.top();
    }
};