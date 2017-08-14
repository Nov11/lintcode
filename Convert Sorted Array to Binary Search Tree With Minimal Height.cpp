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
    TreeNode* work(vector<int>& nums, int beg, int end){
        if(beg >= end){return nullptr;}
        int mid = beg + (end - beg) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = work(nums, beg, mid);
        root->right = work(nums, mid + 1, end);
        return root;
    }
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return work(A, 0, A.size());
    }
};


