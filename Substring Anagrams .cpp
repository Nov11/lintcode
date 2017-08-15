class Solution {
public:
    /**
     * @param s a string
     * @param p a non-empty string
     * @return a list of index
     */
    vector<int> findAnagrams(string& s, string& p) {
        // Write your code here
        if(s.size() < p.size()){return {};}
        vector<int> v(26);
        for(auto item : p){v[item - 'a']++;}
        vector<int> cur(26);
        vector<int>result;
        int len = p.size();
        for(int i = 0, j = 0; j < s.size(); j++){
            if(j - i == len){
                cur[s[i] - 'a']--;
                i++;
                cur[s[j] - 'a']++;
            }else{
                cur[s[j] - 'a']++;
            }
            if(cur == v){
                result.push_back(i);
            }
        }
        
        return result;
    }
};