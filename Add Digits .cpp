class Solution {
public:
    /**
     * @param num a non-negative integer
     * @return one digit
     */
    int addDigits(int num) {
        // Write your code here
        while(num / 10){
            int tmp = 0;
            while(num){
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};