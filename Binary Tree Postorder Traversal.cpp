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
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        deque<int> d;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
            if(p){
                d.push_front(p->val);
                s.push(p);
                p = p->right;
            }else{
                p = s.top();
                s.pop();
                p = p->left;
            }
        }
        
        return vector<int>(d.begin(), d.end());
    }
};