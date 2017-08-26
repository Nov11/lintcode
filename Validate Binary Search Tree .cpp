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
    bool valid(TreeNode* root, long long lower, long long upper){
        if(!root){return true;}
        if(!(root->val > lower && root->val < upper)){return false;}
        
        if(valid(root->left, lower, root->val) && valid(root->right, root->val, upper)){
            return true;
        }
        
        return false;
    }
public:
    /*
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};