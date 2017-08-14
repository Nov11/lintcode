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
    int height(TreeNode* root, bool& balanced){
        balanced = true;
        if(!root){return 0;}
        bool bl, br;
        int left = height(root->left, bl);
        if(!bl){balanced = false; return 0;}
        int right = height(root->right, br);
        if(!br){balanced = false; return 0;}
        
        if(abs(left - right) > 1){balanced = false;}
        return max(left, right) + 1;
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        bool result;
        height(root, result);
        return result;
    }
};