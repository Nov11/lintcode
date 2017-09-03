class Solution {
	unordered_map<int, string> hash{
		{ 4 ,"IV" },{ 9, "IX" },{ 40,"XL" },{ 90,"XC" },{ 400,"CD" },{ 900,"CM" },{ 1,"I" },
		{ 5, "V" },{ 10,"X" },{ 50,"L" },{ 100,"C" },{ 500,"D" },{ 1000,"M" }
	};
	void work(string& result, int orignial, int n) {
		int number = orignial / n * n;
		if (hash.find(number) != hash.end()) {
			result.append(hash[number]);
		}
		else {
		    int cnt = orignial / n;
		    if(cnt >= 5){
		        result.append(hash[5 * n]);
		        cnt -= 5;
		    }
			for (int i = 0; i < cnt; i++) {
				result.append(hash[n]);
			}
		}
	}
public:
	/*
	* @param n: The integer
	* @return: Roman representation
	Number
	4 IV
	9 IX
	40 XL
	90 XC
	400 CD
	900 CM
	1 I
	5 V
	10 X
	50 L
	100 C
	500 D
	1,000 M
	*/
	string intToRoman(int n) {
		// write your code here
		string result;
		work(result, n, 1000);
		n %= 1000;
		work(result, n, 100);
		n %= 100;
		work(result, n, 10);
		n %= 10;
		work(result, n, 1);
		return result;
	}
};