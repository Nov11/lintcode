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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        // write your code here
        if(inorder.empty()){return nullptr;}
        
        int root = preorder.front();
        int i = 0;
        for(; i < inorder.size(); i++){
            if(inorder[i] == root){break;}
        }
        TreeNode* result = new TreeNode(root);
        vector<int> ileft(inorder.begin(), inorder.begin() + i);
        vector<int> iright(inorder.begin() + i + 1, inorder.end());
        
        vector<int> pleft(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> pright(preorder.begin() + i + 1, preorder.end());
        result->left = buildTree(pleft, ileft);
        result->right = buildTree(pright, iright);
        return result;
    }
};