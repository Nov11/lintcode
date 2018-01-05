class Solution {
public:
	/*
	* @param expression: A string array
	* @return: The Reverse Polish notation of this expression
	*/
	vector<string> convertToRPN(vector<string> &expression) {
		// write your code here
		stack<vector<string>> stk1;
		stack<string> stk2;
		for (auto &item : expression) {
			if (item == "(") {
				stk2.push(item);
			}
			else if (item == ")") {
				while (stk2.top() != "(") {
					vector<string> tmp = stk1.top();
					stk1.pop();
					string op = stk2.top();
					stk2.pop();
					vector<string>& ref = stk1.top();
					ref.insert(ref.end(), tmp.begin(), tmp.end());
					ref.insert(ref.end(), op);
				}
				stk2.pop();
			}
			else if (item == "+" || item == "-" || item == "*" || item == "/") {
				while (!stk2.empty() && stk2.top() != "("
					&& ((stk2.top() == "*" || stk2.top() == "/") || item == "+" || item == "-")) {
					vector<string> tmp = stk1.top();
					stk1.pop();
					string op = stk2.top();
					stk2.pop();
					vector<string>& ref = stk1.top();
					ref.insert(ref.end(), tmp.begin(), tmp.end());
					ref.insert(ref.end(), op);
				}
				stk2.push(item);
			}
			else {
				stk1.push({ item });
			}
		}

		while (!stk2.empty()) {
			vector<string> tmp = stk1.top();
			stk1.pop();
			string op = stk2.top();
			stk2.pop();
			vector<string>& ref = stk1.top();
			ref.insert(ref.end(), tmp.begin(), tmp.end());
			ref.insert(ref.end(), op);
		}

		if (stk1.empty()) {
			return {};
		}
		return stk1.top();
	}
};