class Solution {
public:

	/*
	* @param s: A string
	* @return: the length of last word
	*/
	int lengthOfLastWord(string s) {
		// write your code here
		int len = s.size();
		int tail = -1;
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] != ' ') { tail = i; break; }
		}
		if(tail == -1){return 0;}
		
		int beg = tail;
		for (int i = tail; i >= 0; i--) {
			if (s[i] != ' ') { beg = i; }
			else { break; }
		}

		return tail - beg + 1;
	}
};