class Solution {
public:
    /*
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int len = S.size();
        if(len <= 2){return 0;}
        
        sort(S.begin(), S.end());
        int result = 0;
        for(int i = 0; i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++){
                int sum = S[i] + S[j];
                auto iter = lower_bound(S.begin(), S.end(), sum);
                int cnt = distance(S.begin() + j + 1, iter);
                result += cnt > 0 ? cnt : 0;
            }
        }
        return result;
    }
};