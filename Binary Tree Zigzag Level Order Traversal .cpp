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
public:
    /*
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if(!root){return result;}
        int cnt = 1;
        vector<TreeNode*> level{root};
        while(!level.empty()){
            vector<TreeNode*> next;
            vector<int> tmp;
            for(auto item : level){
                tmp.push_back(item->val);
                if(item->left){next.push_back(item->left);}
                if(item->right){next.push_back(item->right);}
            }
            if(cnt % 2 == 0){
                reverse(tmp.begin(), tmp.end());
            }
            result.push_back(tmp);
            swap(next, level);
            cnt++;
        }
        
        return result;
    }
};