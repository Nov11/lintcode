class Solution {
public:
    /*
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here
        if(path.empty() || path[0] != '/'){return path;}
        vector<string> v;
        size_t e = 0;
        do{
            size_t pos = e + 1;
            e = path.find('/', pos);
            string tmp;
            if(e == string::npos){
                tmp = path.substr(pos);
            }else{
                tmp = path.substr(pos, e - pos);
            }
                
            if(tmp == "." || tmp.empty()){
                //nothing
            }else if(tmp == ".."){
                if(!v.empty()){
                    v.pop_back();
                }
            }else{
                v.push_back(tmp);
            }
        }while(e != string::npos);
        string result;
        for(auto item : v){
            result.append("/").append(item);
        }
        return result.empty() ? "/" : result;
    }
};