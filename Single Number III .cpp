class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> A) {
        // write your code here
        int x = 0;
        for(auto item : A){
            x ^= item;
        }
        
        int bit1 = x - (x & (x - 1));
        
        int i = 0;
        int j = 0;
        for(auto item : A){
            if(item & bit1){
                i ^= item;
            }else{
                j ^= item;
            }
        }
        
        return {i, j};
    }
};