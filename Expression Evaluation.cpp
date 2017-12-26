class Solution {
    bool no_less_priority(char op1, char op2) {
        if (op1 == '(') { return false; }
        if (op1 == '*' || op1 == '/') { return true; }
        if (op2 == '+' || op2 == '-') { return true; }
        return false;
    }

    void do_math(stack<int> &s1, stack<char> &s2) {
        int oper2 = s1.top();
        s1.pop();
        char op = s2.top();
        s2.pop();
        switch (op) {
            case '+':
                s1.top() = s1.top() + oper2;
                break;
            case '-':
                s1.top() -= oper2;
                break;
            case '*':
                s1.top() *= oper2;
                break;
            case '/':
                s1.top() /= oper2;
        }
    }

public:
    /*
     * @param expression: a list of strings
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        stack<int> s1;
        stack<char> s2;

        for (int i = 0; i < expression.size(); i++) {
            string &cur = expression[i];
            if (cur[0] == '(') {
                s2.push('(');
            } else if (cur[0] == '+' || cur[0] == '-' || cur[0] == '*' || cur[0] == '/') {
                while (!s2.empty() && no_less_priority(s2.top(), cur[0])) {
                    do_math(s1, s2);
                }
                s2.push(cur[0]);
            } else if (cur[0] == ')') {
                while (s2.top() != '(') {
                    do_math(s1, s2);
                }
                s2.pop();
            } else {
                s1.push(stoi(cur));
            }
        }

        while (!s2.empty()) {
            do_math(s1, s2);
        }

        if (s1.empty()) { return 0; }
        return s1.top();
    }
};
