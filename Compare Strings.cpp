class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        vector<int> va(26);
        for(auto item : A){
            va[item - 'A']++;
        }
        for(auto item : B){
            if(--va[item - 'A'] < 0){
                return false;
            }
        }
        
        return true;
    }
};