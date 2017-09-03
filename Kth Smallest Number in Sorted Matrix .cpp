class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        priority_queue<int> q;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                q.push(matrix[i][j]);
                if(q.size() > k){
                    q.pop();
                }
            }
        }
        
        return q.empty() ? 0 : q.top();
    }
};