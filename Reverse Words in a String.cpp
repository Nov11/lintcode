class Solution {
public:
	/**
	* @param s : A string
	* @return : A string
	*/
	string reverseWords(string s) {
		// write your code here
		stringstream ss(s);
		vector<string> v;
		while (ss) {
			string tmp;
			ss >> tmp;
			v.push_back(tmp);
		}

		string result;
		while (!v.empty()) {
			if (!result.empty()) { result.append(" "); }
			result.append(v.back());
			v.pop_back();
		}

		return result;
	}
};