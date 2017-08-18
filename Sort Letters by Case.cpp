class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        int j = letters.size();
        int i = 0;
        j--;
        while(i < j){
            while(i < j && islower(letters[i])){i++;}
            while(i < j && isupper(letters[j])){j--;}
            if(i < j){
                swap(letters[i], letters[j]);
                i++;
                j--;
            }else{
                break;
            }
        }
    }
};
