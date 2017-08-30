class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<string>> hash;

        for(auto& item : strs){
            string tmp = item;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(item);
        }
        
        vector<string> result;
        for(auto& item : hash){
            if(item.second.size() > 1){
                result.insert(result.end(), item.second.begin(), item.second.end());
            }
        }
        return result;
    }
};
