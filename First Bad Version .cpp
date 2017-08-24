/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int i = 1;
        int j =n;
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(SVNRepo::isBadVersion(mid)){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
        return j + 1;
    }
};
