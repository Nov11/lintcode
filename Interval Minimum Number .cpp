/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
    struct SegmentTreeNode{
        int start;
        int end;
        int min;
        SegmentTreeNode(int s, int e):start(s),end(e){}
        SegmentTreeNode* left, *right;
    };
    void modify(SegmentTreeNode * root, int index, int value) {
        // write your code here
        if(!root){return;}
        if(root->start == root->end && root->start == index){
            root->min = value;
            return;
        }
        
        if((root->start + root->end) / 2 >= index){
            modify(root->left, index, value);
        }else{
            modify(root->right, index, value);
        }
        
        root->min = min(root->left->min, root->right->min);
    }
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
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        if(!root || root->start > start || root->end < end){return -1;}
        if(root->start == start && root->end == end){
            return root->min;
        }
        
        if(end <= (root->start + root->end) / 2){
            return query(root->left, start, end);
        }
        if(start >= (root->start + root->end) / 2 + 1){
            return query(root->right, start, end);
        }
        
        int left = query(root->left, start, (root->start + root->end) / 2);
        int right = query(root->right, (root->start + root->end) / 2 + 1, end);
        return min(left, right);
    }
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        int len = A.size();
        using Node = SegmentTreeNode;
        Node* root = build(0, len-1);
        for(int i = 0; i < len; i++){
            modify(root, i, A[i]);
        }
        
        vector<int> result;
        for(auto& item : queries){
            result.push_back(query(root, item.start, item.end));
        }
        return result;
    }
};