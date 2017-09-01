class Solution {
    void work(vector<int>& result, int position, int prefix){
        if(position == -1){if(prefix!=0){result.push_back(prefix);}return;}
        
        int shift = pow(10, position);
        for(int i = 0; i < 10; i++){
            work(result, position - 1, prefix + shift * i);
        }
    }
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> result;
        work(result, n - 1, 0);
        return result;
    }
};