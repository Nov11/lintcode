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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(!root){return root;}
        if(root == A || root == B){return root;}
        auto left = lowestCommonAncestor(root->left, A, B);
        if(left != A && left != B && left != nullptr){return left;}
        auto right = lowestCommonAncestor(root->right, A, B);
        if(left != A && left != B && left != nullptr){return right;}
        if(left == A && right == B || left == B && right == A){
            return root;
        }
        if(left){return left;}
        if(right){return right;}
        return nullptr;
    }
};