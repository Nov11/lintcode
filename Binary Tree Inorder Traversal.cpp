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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
            if(p == nullptr){
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }else{
                s.push(p);
                p = p->left;
            }
        }
        
        return result;
    }
};