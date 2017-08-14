class Solution {
public:
	/*
	* @param string: An array of Char
	* @param length: The true length of the string
	* @return: The true length of new string
	*/
	int replaceBlank(char string[], int length) {
		// write your code here
		int spaces = 0;
		int chars = 0;
		for (int i = 0; i < length; i++) {
			if (string[i] == ' ') {
				spaces++;
			}
			else {
				chars++;
			}
		}
		int di = chars + spaces * 3 - 1;
		int si = chars + spaces - 1;

		for (; si >= 0; si--) {
			if (string[si] == ' ') {
				string[di] = '0';
				string[di - 1] = '2';
				string[di - 2] = '%';
				di -= 3;
			}
			else {
				string[di] = string[si];
				di--;
			}
		}

		return chars + spaces * 3;
	}
};