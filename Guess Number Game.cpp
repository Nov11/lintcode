// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        // Write your code here
        int head = 1;
        int tail = n;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            int ret = guess(mid) ;
            if(ret == 0){return mid;}
            else if(ret > 0){head = mid + 1;}
            else{tail = mid - 1;}
        }
    }
};