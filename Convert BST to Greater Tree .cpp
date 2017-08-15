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
    int work(TreeNode* root, int v){
        if(!root){return v;}
        int ret = work(root->right, v);
        root->val += ret;
        return work(root->left, root->val);
    }
public:
    /**
     * @param root the root of binary tree
     * @return the new root
     */
    TreeNode* convertBST(TreeNode* root) {
        // Write your code here
        work(root, 0);
        return root;
    }
};