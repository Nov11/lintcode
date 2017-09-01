class Solution {
    class SegmentTreeNode {
    public:
        int start, end;
        int count;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int start, int end) {
            this->start = start, this->end = end;
            this->left = this->right = NULL;
            count = 0;
        }
    };
    using Node = SegmentTreeNode;
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end){return nullptr;}
        using Node = SegmentTreeNode;
        Node* result = new Node(start, end);
        if(start != end){
            result->left =build(start, (start + end) / 2);
            result->right = build((start + end) / 2 + 1, end);
            result->count = result->left->count + result->right->count;
        }else{
            result->count = hash[start];
        }
        return result;
    }
    
    int query(Node* root, int start, int end){
        start = max(0, start);
        end = min(10001, end);
        if(!root || start > end){return 0;}
        if(root->start > end || root->end < start){return 0;}
        if(root->start == start && root->end <= end){return root->count;}
        int mid = (root->start + root->end) / 2;
        if(end <= mid){
            return query(root->left, start, end);
        }else if(start > mid){
            return query(root->right, start, end);
        }
        return query(root->left, start, mid) + query(root->right, mid + 1, end);
    }
    unordered_map<int, int> hash;
public:
    /*
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> A, vector<int> queries) {
        // write your code here
        for(auto item : A){
            hash[item]++;
        }
        auto n = build(0, 10000);
        vector<int> result;
        for(auto item : queries){
            result.push_back(query(n, 0, item - 1));
        }
        return result;
    }
};