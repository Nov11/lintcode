class Solution {
	struct Item {
		//maybe a union is better
		string str;
		int cnt;
		bool isNumber_;
		Item(int i) :cnt(i), isNumber_(true) {}
		Item(string s) :str(s), cnt(0), isNumber_(false){}
		bool isNumber() { return isNumber_; }
	};
public:
	/*
	* @param s: an expression includes numbers, letters and brackets
	* @return: a string
	*/
	string expressionExpand(string &s) {
		// write your code here
		stack<Item> stk;
		for (int i = 0; i < s.size(); ) {
			if (isdigit(s[i])) {
				int v = s[i] - '0';
				while (++i < s.size() && isdigit(s[i])) {
					v *= 10;
					v += s[i] - '0';
				}
				stk.push(Item(v));
			}
			else if (isalpha(s[i])) {
				string tmp(1, s[i]);
				while (++i < s.size() && isalpha(s[i])) {
					tmp.push_back(s[i]);
				}

				stk.push(Item(tmp));
			}
			else if (s[i] == ']') {
				string literal;
				while (!stk.empty() && !stk.top().isNumber()) {
					literal = stk.top().str + literal;
					stk.pop();
				}
				int cnt = stk.top().cnt;
				stk.pop();

				string replicate;
				for (int j = 0; j < cnt; j++) {
					replicate.append(literal);
				}
				i++;
				if(replicate.empty()){
					//nothing
				}
				else {
					stk.push(Item(replicate));
				}
			}
			else {
				//get over '[' 
				//do nothing
				i++;
			}
		}
		string result;
		while (!stk.empty()) {
			result = stk.top().str + result;
			stk.pop();
		}
		return result;
	}
};