class Solution {
public:
    /**
     * @param num1 a non-negative integers
     * @param num2 a non-negative integers
     * @return return sum of num1 and num2
     */
    string addStrings(string& num1, string& num2) {
        // Write your code here
        string result;
        //non negative integer -> not empty for sure
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        int carry = 0;
        while(i1 >= 0 || i2 >= 0){
            int v1 = i1 >= 0 ? num1[i1--] - '0' : 0;
            int v2 = i2 >= 0 ? num2[i2--] - '0' : 0;
            int digit = v1 + v2 + carry;
            result.push_back(digit % 10 + '0');
            carry = digit / 10;
        }
        
        if(carry){result.push_back('1');}
        reverse(result.begin(), result.end());
        return result;
    }
};