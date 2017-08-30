class Solution {
    void doUnion(vector<int>& v, int r1, int r2){
        if(r1 > r2){swap(r1, r2);}
        v[r2] = r1;
    }
    
    int find(vector<int>& v, int n){
        while(v[n] != -1){
            n = v[n];
        }
        return n;
    }
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if(edges.size() != n - 1){return false;}
        
        vector<int> v(n, -1);
        for(auto e : edges){
            int r1 = find(v, e[0]);
            int r2 = find(v, e[1]);
            if(r1 == r2){return false;}
            doUnion(v, r1, r2);
        }
        
        return true;
    }
};