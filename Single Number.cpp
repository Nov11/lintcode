class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int result = 0;
        for(auto item : A){
            result ^= item;
        }
        return result;
    }
};