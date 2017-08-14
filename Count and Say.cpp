class Solution {
public:

	/*
	* @param n: the nth
	* @return: the nth sequence
	*/
	string countAndSay(int n) {
		// write your code here
		string result{ "1" };
		for (int i = 2; i <= n; i++) {
			string tmp;
			int cnt = 1;
			char c = result[0];
			for (int j = 1; j < result.size(); j++) {
				if (result[j] == c) { cnt++; }
				else { tmp.append(to_string(cnt)).push_back(c); cnt = 1; c = result[j]; }
			}
			tmp.append(to_string(cnt));
			tmp.push_back(c);

			swap(result, tmp);
		}

		return result;
	}
};