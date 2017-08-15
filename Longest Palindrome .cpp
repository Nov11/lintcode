class Solution {
public:
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        // Write your code here
        unordered_map<char, int> hash;
        for(auto item : s){hash[item]++;}
        int result = 0;
        int oddcnt = 0;
        for(auto item : hash){
            if(item.second % 2 == 0){result += item.second;}
            else{oddcnt ++; result += item.second - 1;}
        }
        if(oddcnt >= 1){result++;}
        return result;
    }
};