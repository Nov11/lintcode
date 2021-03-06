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
    void inorder(TreeNode* root, int k1, int k2, vector<int>& result){
        if(!root){return;}
        int val = root->val;
        if(val >= k1){inorder(root->left, k1, k2, result);}
        if(val >= k1 && val <= k2){result.push_back(val);}
        if(val <= k2){inorder(root->right, k1, k2, result);}
    }
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> result;
        inorder(root, k1, k2, result);
        return result;
    }
};