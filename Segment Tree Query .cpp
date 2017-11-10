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
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        if(!root || root->start > start || root->end < end){return -1;}
        if(root->start == start && root->end == end){
            return root->max;
        }
        
        if(end <= (root->start + root->end) / 2){
            return query(root->left, start, end);
        }
        if(start >= (root->start + root->end) / 2 + 1){
            return query(root->right, start, end);
        }
        
        int left = query(root->left, start, (root->start + root->end) / 2);
        int right = query(root->right, (root->start + root->end) / 2 + 1, end);
        return max(left, right);
    }
};