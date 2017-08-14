class Solution {
public:
    
    /*
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string s) {
        // write your code here
        if(s.empty()){return true;}
        
        int len = s.size();
        int head = 0;
        int tail = len - 1;
        while(head <= tail){
            while(head < len && !isalnum(s[head])){head++;}
            while(tail >= 0 && !isalnum(s[tail])){tail--;}
            if(head >= tail){break;}
            else if(tolower (s[head]) == tolower (s[tail])){head++; tail--;}
            else {return false;}
        }
        return true;
    }
};