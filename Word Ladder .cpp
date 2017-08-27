class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if(start == end){return 1;}//wtf!
        int step = 0;
        dict.insert(end);
        vector<string> v{start};
        while(!v.empty()){
            step++;
            vector<string> next;
            for(auto item : v){
                for(int i = 0; i < item.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        if(item[i] == c){continue;}
                        string tmp = item;
                        tmp[i] = c;

                        if(dict.find(tmp) != dict.end()){
                            if(tmp == end){
                                return step + 1;
                            }
                            next.push_back(tmp);
                            dict.erase(tmp);
                        }
                    }
                }
            }
            swap(next, v);
        }
        
        return 0;
    }
};