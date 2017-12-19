class Solution {
public:
	string mul10(string a, int k) {
		if (a.empty() || a == "0" || k == 0) {
			return a;
		}
		return a + string(k, '0');
	}

	string mul(string a, string b) {
		string result;
		int i = b.size();
		i--;
		for (int j = 0; i >= 0; i--, j++) {
			auto ret = mul10(do_mul(a, b[i] - '0'), j);
			result = add(result, ret);
		}
		return result;
	}

	string add(const string& a, const string &b) {
		if (b.empty()) { return a; }
		int carry = 0;
		int idxa = a.size();
		idxa--;
		int idxb = b.size();
		idxb--;
		string result;
		while (idxa >= 0 || idxb >= 0) {
			int ca = idxa >= 0 ? a[idxa--] - '0' : 0;
			int cb = idxb >= 0 ? b[idxb--] - '0' : 0;
			int n = (ca + cb + carry);
			carry = n / 10;
			result.push_back('0' + n % 10);
		}

		if (carry) {
			result.push_back('1');
		}
		reverse(result.begin(), result.end());
		return result;
	}

	string do_mul(const string& a, int b) {
		int carry = 0;
		string result;

		int idx = a.size();
		idx--;
		while (idx >= 0) {
			int n = a[idx--] - '0';
			n *= b;
			n += carry;
			result.push_back('0' + n % 10);
			carry = n/ 10;
		}
		if (carry) {
			result.push_back(carry + '0');
		}
		reverse(result.begin(), result.end());

		return result;
	}

public:
	/*
	* @param : an integer
	* @return:  the factorial of n
	*/
	string factorial_old(int n) {
		// write your code here
		if (n == 0) {
		    return "1";
		}
		if (n == 1) {
			return "1";
		}

        string result("1");
        for(int i = 2; i <= n; i++){
            result = mul(result, to_string(i));
        }
// 		auto ret= mul(to_string(n), factorial(n - 1));

		return result;
	}
	
	string factorial(int n) {
	    vector<char> result;
	    result.push_back('1');

	    long long carry = 0;
	    for(int i = 2; i <= n; i++){
	        for(int j = 0; j < result.size(); j++){
	            int cur = result[j] - '0';
	            carry += cur * i;
	            result[j] = carry % 10 + '0';
	            carry /= 10;
	        }
	        while(carry){
	            result.push_back(carry % 10 + '0');
	            carry /= 10;
	        }
	    }
	    
	    string ret(result.begin(), result.end());
	    reverse(ret.begin(), ret.end());
	    return ret;
	}
};