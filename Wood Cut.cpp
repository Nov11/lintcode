class Solution {
    int count(vector<int>& v, int len){
        int result = 0;
        for(auto item : v){
            result += item / len;
        }
        return result;
    }
public:
    /*
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        int len = L.size();
        long long sum = accumulate(L.begin(), L.end(), 0L);
        
        if(len == 0 || sum / k < 1){return 0;}
        int first = 1;
        int last = sum / k;
        while(first <= last){
            int mid = first + (last - first) / 2;
            int ret = count(L, mid);
            if(ret < k){
                last = mid - 1;
            }else{
                first = mid + 1;
            }
        }
        
        if(last < 1){
            return 0;
        }
        return last;
    }
};
//232 124 456
//356 ->812
///7->116
//116 116 116 8 116 116 116 108  ->6*116