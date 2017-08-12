class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        if(root == nullptr){return nullptr;}
        if(root->left == nullptr && root->right == nullptr){
            return root;
        }
        
        TreeNode* left = maxNode(root->left);
        TreeNode* right = maxNode(root->right);
        
        TreeNode* result = root;
        if(left != nullptr && result->val < left->val){result = left;}
        if(right != nullptr && result->val < right->val){result = right;}
        
        return result;
    }
};