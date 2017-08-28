class Solution {
public:
    /*
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> num) {
        // write your code here
        unordered_set<int> s(num.begin(), num.end());
        int result = 0;
        for(auto item : num){
            if(s.find(item) == s.end()){
                continue;
            }
            
            int tmp = 1;
            for(int i = item + 1; s.find(i) != s.end(); i++){
                tmp++;
                s.erase(i);
            }
            
            for(int i = item - 1; s.find(i) != s.end(); i--){
                tmp++;
                s.erase(i);
            }
            result = max(result, tmp);
        }
        
        return result;
    }
};