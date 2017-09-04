class Solution {
    void work(vector<string>& result, vector<int>& path, string& s, int idx, int cnt){
        if(idx == s.size() && cnt == 4){
            string tmp = to_string(path[0]);
            for(int i = 1; i < 4; i++){
                tmp.append(".").append(to_string(path[i]));
            }
            result.push_back(tmp);
            return;
        }
        if(idx == s.size() || cnt == 4){return;}
        
        int n = 0;
        for(int i = 1; i <= 3 && idx < s.size(); i++, idx++){
            n *= 10;
            n += s[idx] - '0';
            if(i == 2 && n < 10){return;}
            if(i == 3 && (n > 255 || n < 100)){return;}
            
            path.push_back(n);
            work(result, path, s, idx+1, cnt+1);
            path.pop_back();
        }
    }
public:
    /*
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string &s) {
        // write your code here
        vector<string> result;
        vector<int> path;
        work(result, path, s, 0, 0);
        return result;
    }
};