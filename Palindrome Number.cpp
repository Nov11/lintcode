class Solution {
public:
    
    /*
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        if(num <= 0){return false;}
        int ori = num;
        long long tmp = 0;
        while(num){
            tmp *= 10;
            tmp += num % 10;
            num /= 10;
        }
        
        return tmp == ori;
    }
};