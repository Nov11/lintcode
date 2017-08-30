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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        using Node = DirectedGraphNode;
        if(s == t){return true;}
        vector<Node*> v{s};
        set<Node*> visited;
        while(!v.empty()){
            vector<Node*> next;
            for(auto item : v){
                if(visited.find(item) != visited.end()){continue;}
                
                for(auto link : item->neighbors){
                    if(link == t){
                        return true;
                    }
                    next.push_back(link);
                }
                visited.insert(item);
            }
            swap(next, v);
        }
        return false;
    }
};

