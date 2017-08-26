class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        vector<int> acc(sizeof(int) * 8);
        for(auto item : A){
            for(int i = 0; i < sizeof(int) * 8 && item != 0; i++){
                int mask = 1 << i;
                if(item & mask){
                    acc[i]++;
                    item &= (~mask);
                }
            }
        }
        int result = 0;
        for(int i = 0; i < acc.size(); i++){
            if(acc[i] % 3 != 0){
                result |= 1 << i;
            }
        }
        
        return result;
    }
};