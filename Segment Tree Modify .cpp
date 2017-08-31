/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param index: index.
     * @param value: value
     * @return: 
     */
    void modify(SegmentTreeNode * root, int index, int value) {
        // write your code here
        if(!root){return;}
        if(root->start == root->end && root->start == index){
            root->max = value;
            return;
        }
        
        if((root->start + root->end) / 2 >= index){
            modify(root->left, index, value);
        }else{
            modify(root->right, index, value);
        }
        
        root->max = max(root->left->max, root->right->max);
    }
};