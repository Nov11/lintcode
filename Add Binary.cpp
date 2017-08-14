class Solution {
public:

	/*
	* @param a: a number
	* @param b: a number
	* @return: the result
	*/
	string addBinary(string a, string b) {
		// write your code here
		string result;
		int carry = 0;
		auto iterA = a.rbegin();
		auto iterB = b.rbegin();
		while (iterA != a.rend() || iterB != b.rend()) {
			int aa = iterA == a.rend() ? 0 : *iterA++ - '0';
			int bb = iterB == b.rend() ? 0 : *iterB++ - '0';
			result.push_back((aa + bb + carry) % 2 + '0');
			carry = (aa + bb + carry) / 2;
		}
		if (carry) { result.push_back('1'); }
		reverse(result.begin(), result.end());
		return result;
	}
};