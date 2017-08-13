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
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        stack<TreeNode*> s;
        TreeNode* p = root;
        vector<int> result;
        while(p != nullptr || !s.empty()){
            if(p == nullptr){
                p = s.top();
                s.pop();
            }else{
                result.push_back(p->val);
                s.push(p->right);
                p = p->left;
            }
        }
        return result;
    }
};
