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
    using Node = SegmentTreeNode;
    Node* work(vector<int>& A, int start, int end){
        if(start == end){
            return new Node(start, end, A[start]);
        }
        
        Node* node = new Node(start, end, 0);
        node->left = work(A, start, (start + end) / 2);
        node->right = work(A, (start + end) / 2 + 1, end);
        node->max = max(node->left->max, node->right->max);
        return node;
    }
public:
    /*
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        // write your code here
        if(A.empty()){return nullptr;}
        
        return work(A, 0, A.size() - 1);
    }
};