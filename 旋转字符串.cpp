class Solution {
public:
	/**
	* @param str: a string
	* @param offset: an integer
	* @return: nothing
	*/
	void rotateString(string &str, int offset) {
		//wirte your code here
		int len = str.size();
		if (len <= 1) { return; }
		offset %= len;
		reverse(str.begin(), str.begin() + len - offset);
		reverse(str.begin() + len - offset, str.end());
		reverse(str.begin(), str.end());
	}
};