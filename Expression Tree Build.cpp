/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
	using TN = ExpressionTreeNode;

public:
	/*
	* @param expression: A string array
	* @return: The root of expression tree
	*/
	ExpressionTreeNode * build(vector<string> &expression) {
		// write your code here
		stack<TN*> s1;
		stack<TN*> s2;

		for (int i = 0; i < expression.size(); i++) {
			string cur = expression[i];
			TN* node = new TN(cur);
			if (cur == "(") {
				s2.push(node);
			}else if (cur == "+" || cur == "-" || cur == "*" || cur == "/") {
				//if (s2.empty() || s2.top()->symbol == "(") {
				//	s2.push(node);
				//}
				//else {
				//	if ((s2.top()->symbol == "*" || s2.top()->symbol == "/") || (cur == "-" || cur == "+")) {
				//		TN* op = s2.top();
				//		s2.pop();
				//		TN* op2 = s1.top();
				//		s1.pop();
				//		TN* op1 = s1.top();
				//		op->left = op1;
				//		op->right = op2;
				//		s1.top() = op;

				//		s2.push(node);
				//	}
				//	else {
				//		s2.push(node);
				//	}
				//}
				while (!(s2.empty() || s2.top()->symbol == "(")) {
					if ((s2.top()->symbol == "*" || s2.top()->symbol == "/") || (cur == "-" || cur == "+")) {
						TN* op = s2.top();
						s2.pop();
						TN* op2 = s1.top();
						s1.pop();
						TN* op1 = s1.top();
						op->left = op1;
						op->right = op2;
						s1.top() = op;
					}
					else {
						break;
					}
				}
				s2.push(node);
			}
			else if (cur == ")") {
				while (!s2.empty() && s2.top()->symbol != "(") {
					TN* op = s2.top();
					s2.pop();
					TN* right = s1.top();
					s1.pop();
					TN* left = s1.top();
					op->left = left;
					op->right = right;
					s1.top() = op;
				}
				if (s2.top()->symbol == "(") {
					s2.pop();
				}
			}
			else {
				s1.push(node);
			}
		}

		while (!s2.empty()) {
			TN* op = s2.top();
			s2.pop();
			TN* right = s1.top();
			s1.pop();
			TN* left = s1.top();
			op->left = left;
			op->right = right;
			s1.top() = op;
		}
		if (s1.empty()) {
			return nullptr;
		}
		return s1.top();
	}
};