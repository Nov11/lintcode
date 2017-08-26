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
    int result = INT_MIN;
    int work(TreeNode* root){
        if(!root){return 0;}
        auto left = work(root->left);
        auto right = work(root->right);
        int sum = max(root->val, max(root->val + left, root->val + right));
        result = max(result, max(sum, root->val + left + right));
        return sum;
    }
public:
    /*
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        // write your code here
        if(!root){return 0;}
        
        work(root);
        return result;
    }
};