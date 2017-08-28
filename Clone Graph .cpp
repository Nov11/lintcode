/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(!node){return node;}
        using Node = UndirectedGraphNode;
        
        unordered_map<Node*, Node*> hash;
        set<Node*> copied;
        Node* result = new Node(node->label);
        hash[node] = result;
        vector<Node*> v{node};
        while(!v.empty()){
            vector<Node*> next;
            for(auto item : v){
                if(copied.find(item) != copied.end()){
                    continue;   
                }
                Node* newNode = hash[item];
                for(auto link : item->neighbors){
                    if(hash.find(link) != hash.end()){
                        newNode->neighbors.push_back(hash[link]);
                    }else{
                        auto create = new Node(link->label);
                        hash[link] = create;
                        newNode->neighbors.push_back(create);
                    }
                }
                copied.insert(item);
                next.insert(next.end(), item->neighbors.begin(), item->neighbors.end());
            }
            
            swap(next, v);
        }
        
        return result;
    }
};