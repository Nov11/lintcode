/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
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
     * @return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        start = max(start, 0);
        if(!root || start > end || root->start > end || root->end < start){return 0;}
        if(root->start == start && root->end <= end){return root->count;}
        int mid = (root->start + root->end) / 2;
        if(end <= mid){
            return query(root->left, start, end);
        }else if(mid + 1 <= start){
            return query(root->right, start, end);
        }
        auto left = query(root->left, start, mid);
        auto right = query(root->right, mid + 1, end);
        return left + right;
    }
};