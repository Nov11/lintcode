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
    void work(vector<string>& result, string path, TreeNode* root){
        if(!root->left && !root->right){
            result.push_back(path);
            return;
        }
        if(root->left){
            work(result, path + "->" + to_string(root->left->val), root->left);
        }
        if(root->right){
            work(result, path + "->" + to_string(root->right->val), root->right);
        }
    }
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> result;
        if(!root){return result;}
        string path{to_string(root->val)};
        
        work(result, path, root);
        return result;
    }
};