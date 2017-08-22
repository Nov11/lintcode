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
public:
    /*
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if(!root){return result;}
        
        vector<TreeNode*> level;
        level.push_back(root);
        
        while(!level.empty()){
            vector<int> value;
            vector<TreeNode*> next;
            for(auto item : level){
                value.push_back(item->val);
                if(item->left){next.push_back(item->left);}
                if(item->right){next.push_back(item->right);}
            }
            
            result.push_back(value);
            swap(level, next);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};