class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> result;
        if(dictionary.empty()){return result;}
        
        int len = dictionary[0].size();
        result.push_back(dictionary[0]);
        
        for(int i = 1; i < dictionary.size(); i++){
            int curLen = dictionary[i].size();
            if(len == curLen){result.push_back(dictionary[i]);}
            else if(len < curLen){
                result.clear();
                result.push_back(dictionary[i]);
                len = curLen;
            }
        }
        
        return result;
    }
};