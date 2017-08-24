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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if(inorder.empty()){return nullptr;}
        
        int root = postorder.back();
        int i = 0;
        for(; i < inorder.size(); i++){
            if(inorder[i] == root){break;}
        }
        TreeNode* result = new TreeNode(root);
        vector<int> ileft(inorder.begin(), inorder.begin() + i);
        vector<int> iright(inorder.begin() + i + 1, inorder.end());
        
        vector<int> pleft(postorder.begin(), postorder.begin() + i);
        vector<int> pright(postorder.begin() + i, postorder.begin() + postorder.size() - 1);
        result->left = buildTree(ileft, pleft);
        result->right = buildTree(iright, pright);
        return result;
    }
};