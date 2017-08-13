/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if(!root){return result;}
        vector<TreeNode*> line{root};
        while(!line.empty()){
            vector<int> vl;
            vector<TreeNode*> next;
            for(auto item : line){
                vl.push_back(item->val);
                if(item->left){next.push_back(item->left);}
                if(item->right){next.push_back(item->right);}
            }
            result.push_back(vl);
            swap(line, next);
        }
        
        return result;
    }
};
