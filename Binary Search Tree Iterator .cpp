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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
    stack<TreeNode*> stk;
    void build(){
        if(stk.empty()){return;}
        TreeNode* node = stk.top();
        while(node && node->left){
            stk.push(node->left);
            node = node->left;
        }
    }
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        if(!root){return;}
        stk.push(root);
        
        build();
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return !stk.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode* result = stk.top();
        stk.pop();
        if(result->right){
            stk.push(result->right);
            build();
        }
        
        return result;
    }
};