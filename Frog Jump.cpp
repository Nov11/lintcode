class Solution {
    set<int> s;
    map<pair<int, int>, bool> hash;
    bool work(int last, int curStone){
        if(*s.rbegin() == curStone){return true;}
        
        for(int i = last - 1; i <= last + 1; i++){
            if(i == 0){continue;}
            auto p = make_pair(curStone, i);
            if(hash.find(p) != hash.end()){
                if(hash[p]){
                    return true;
                }
                continue;
            }
            
            int target = curStone + i;
            if(s.find(target) == s.end()){
                continue;
            }
            if(work(i, target)){
                return true;
            }
            hash[make_pair(curStone, i)] = false;
        }
        return false;
    }
public:
    /*
     * @param stones: a list of stones' positions in sorted ascending order
     * @return: true if the frog is able to cross the river or false
     */
    bool canCross(vector<int> &stones) {
        // write your code here
        if(stones.size() <= 1){return true;}
        
        s.insert(stones.begin(), stones.end());
        
        int pos = stones[0];
        if(s.find(pos + 1) == s.end()){
            return false;
        }
        return work(1, pos + 1);
    }
};