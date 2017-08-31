/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param start: start value.
     * @param end: end value.
     * @return: The root of Segment Tree.
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end){return nullptr;}
        using Node = SegmentTreeNode;
        Node* result = new Node(start, end);
        if(start != end){
            result->left =build(start, (start + end) / 2);
            result->right = build((start + end) / 2 + 1, end);
        }
        return result;
    }
};