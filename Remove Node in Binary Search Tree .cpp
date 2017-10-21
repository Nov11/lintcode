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
    TreeNode* del(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr){return nullptr;}
        if(root->right == nullptr){return root->left;}
        TreeNode* n = root->right;
        while(n->left != nullptr){
            n = n->left;
        }
        n->left = root->left;
        return root->right;
    }
public:
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        // write your code here
        if(!root){return root;}
        if(root->val == value){
            return del(root);
        }
        
        TreeNode* n = root;
        TreeNode* prev = nullptr;
        while(n){
            if(n->val == value){break;}
            else if(n->val > value){
                prev = n;
                n = n->left;
            }else{
                prev = n;
                n = n->right;
            }
        }
        
        if(n == nullptr){return root;}
        
        auto ret = del(n);
        if(prev->left == n){prev->left = ret;}
        else{
            prev->right = ret;
        }
        //free node n 
        return root;
    }
};