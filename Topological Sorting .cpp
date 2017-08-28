/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        unordered_map<DirectedGraphNode*, int> hash;
        for(auto item : graph){
            if(hash.find(item) == hash.end()){hash[item] = 0;}
            for(auto i : item->neighbors){
                hash[i]++;
            }
        }
        
        vector<DirectedGraphNode*> result;
        vector<DirectedGraphNode*> zero;
        for(auto item : hash){
            if(item.second == 0){
                zero.push_back(item.first);
            }
        }
        
        while(!hash.empty() && !zero.empty()){
            result.insert(result.end(), zero.begin(), zero.end());
            vector<DirectedGraphNode*> next;
            for(auto item : zero){
                hash.erase(item);
                for(auto i : item->neighbors){
                    hash[i]--;
                    if(hash[i] == 0){
                        next.push_back(i);
                    }
                }
            }
            swap(next, zero);
        }
        
        return result;
    }
};