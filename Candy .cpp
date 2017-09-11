class Solution {
public:
    /*
     * @param ratings: Children's ratings
     * @return: the minimum candies you must give
     */
    int candy(vector<int> &ratings) {
        // write your code here
        if(ratings.empty()){return 0;}
        int len = ratings.size();
        if(len == 1){return 1;}
        
        vector<int> v(len, 1);
        
        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i - 1]){v[i] = v[i - 1] + 1;}
        }
        for(int i = len - 2; i >= 0; i--){
            if(ratings[i + 1] < ratings[i] && v[i] <= v[i + 1]){v[i] = v[i + 1] + 1;}
        }
        
        return accumulate(v.begin(), v.end(), 0);
    }
};