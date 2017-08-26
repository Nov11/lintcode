class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> strs) {
        // write your code here
        if(strs.empty()){return "";}
        vector<char> lst(strs[0].begin(), strs[0].end());
        
        for(int i = 1; i < strs.size(); i++){
            string& cur = strs[i];
            if(cur.empty()){return "";}
            if(cur.size() < lst.size()){
                lst.resize(cur.size());
            }
            for(int j = 0; j < lst.size(); j++){
                if(lst[j] != cur[j]){lst.resize(j);break;}
            }
        }
        
        return string(lst.begin(), lst.end());
    }
};