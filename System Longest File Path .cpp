class Solution {
public:
	/*
	* @param input: an abstract file system
	* @return: return the length of the longest absolute path to file
	*/
	int lengthLongestPath(string &input) {
		// write your code here
		stack<int> stk;
		input = input + "\n";
		int curDirLen = 0;
		int result = 0;
		for (int i = 0; i < input.size(); i++) {
			// string tmp;
			int strLen = 0;
			bool isFile = false;
			int level = 0;
			while (input[i] != '\n') {
				if (input[i] == '\t') { level++; }
				else {
					// tmp.push_back(input[i]);
					strLen++;
					if (input[i] == '.') { isFile = true; }
				}
				i++;
			}
			while (stk.size() > level) {
				int len = stk.top();
				stk.pop();
				curDirLen -= len;
			}
			if (isFile) {
				result = max(result, curDirLen + strLen);//int(tmp.size()));
			}
			else {
				// stk.push(tmp.size() + 1);
				stk.push(strLen + 1);
				curDirLen += stk.top();
			}
		}

		return result;
	}
};