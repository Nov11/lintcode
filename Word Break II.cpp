class Solution {
    bool work(const string& s, int beg, unordered_set<string>& dict, vector<string>& path){
        if(valid[beg] == false){return false;}
        if(beg == s.size()){
            if(path.empty()){
                return false;
            }
            string item = path[0];
            for(int i = 1; i < path.size(); i++){
                item += " ";
                item += path[i];
            }
            result.push_back(item);
            return true;
        }
        string cur;
        bool v = false;
        for(int i = beg; i < s.size() && i - beg + 1 <= maxLen; i++){
            cur.push_back(s[i]);
            // if(next[beg] > i){continue;}
            
            // if(ignore.find(make_pair(beg, i)) != ignore.end()){
            //     continue;
            // }
            if(dict.find(cur) == dict.end()){
                // ignore.insert(make_pair(beg,i));
                // if(i == next[beg]){
                // next[beg]++;}
                continue;
            }
            path.push_back(cur);
            v |= work(s, i + 1, dict, path);
            path.pop_back();
        }
        if(v == false){
            valid[beg] = v;
        }
        return valid[beg];
    }
    vector<string> result;
    // vector<int> next;
    // set<pair<int,int>> ignore;
    vector<bool> valid;
    size_t maxLen = 0;
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        // write your code here
        result.clear();
        // ignore.clear();
        // next.resize(s.size());
        // for(int i = 0; i < s.size(); i++){
        //     next[i] = i;
        // }
        valid = vector<bool>(s.size() + 1, true);
        for(auto& item :wordDict){
            maxLen = max(maxLen, item.size());
        }
        vector<string> path;
        work(s, 0, wordDict, path);
        return result;
    }
};
