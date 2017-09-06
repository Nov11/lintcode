/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */


class Solution {
    vector<int> work(TreeNode* root){
        if(!root){return {0,0};}
        
        auto left = work(root->left);
        auto right =work(root->right);
        vector<int> result;
        result.push_back(root->val + left[1] + right[1]);
        result.push_back(max(left[0], left[1]) + max(right[0], right[1]));
        return result;
    }
public:
    /*
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode * root) {
        // write your code here
        auto ret = work(root);
        return max(ret[0], ret[1]);
    }
};