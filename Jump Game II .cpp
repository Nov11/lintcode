class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // write your code here
        int len = A.size();
        if(len == 1){return 0;}
        
        int first = 0;
        int last = 0;
        int result = 0;
        while(first <= last){
            result++;
            int right = last;
            for(int i = first; i <= right; i++){
                last = max(last, i + A[i]);
            }
            if(last >= len - 1){return result;}
            first = right + 1;
        }
        return -1;
    }
};