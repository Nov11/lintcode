class Solution {
public:
	int partition(vector<string>& v, int beg, int end, const string& s, Comparator compare, bool sIsNut = true) {
		int i = beg;
		int j = end;
		for (int iter = beg; iter < j;) {
			int ret = sIsNut ? compare.cmp(s, v[iter]) * -1 : compare.cmp(v[iter], s);
			if (ret < 0) {
				swap(v[iter], v[i]);
				iter++;
				i++;
			}
			else if (ret == 0) {
				iter++;
			}
			else {
				j--;
				swap(v[j], v[iter]);
			}
		}
		return i;
	}
	void sort(vector<string> &nuts, vector<string> &bolts, int beg, int end, Comparator& compare) {
		if (beg >= end || beg + 1 == end) { return; }
		int ret = partition(bolts, beg, end, nuts[beg], compare);
		partition(nuts, beg, end, bolts[ret], compare,false);
		sort(nuts, bolts, beg, ret, compare);
		sort(nuts, bolts, ret + 1, end, compare);
	}
public:
	/**
	* @param nuts: a vector of integers
	* @param bolts: a vector of integers
	* @param compare: a instance of Comparator
	* @return: nothing
	*/
	void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
		// write your code here
		int len = nuts.size();
		if (len <= 1) { return; }
		sort(nuts, bolts, 0, len, compare);
	}
};