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
    vector<TreeNode*> work(int low, int high){
        if(low > high){
            return {nullptr};
        }
        if(low == high){
            return {new TreeNode(low)};
        }
        
        vector<TreeNode*> result;
        for(int i = low; i <= high; i++){
            auto left = work(low, i - 1);
            auto right = work(i + 1, high);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return work(1, n);
    }
};