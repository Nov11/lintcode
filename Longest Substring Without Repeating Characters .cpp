class Solution {
public:
    /*
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        unordered_map<char, int> hash;
        int beg = 0;
        int len = s.size();
        int result = 0;
        for(int i = 0; i < len; ){
            if(hash[s[i]] < 1){
                hash[s[i]]++;
                result = max(result, i - beg + 1);
                i++;
            }else{
                while(hash[s[i]]){
                    hash[s[beg]]--;
                    beg++;
                }
            }
        }
        
        return result;
    }
};