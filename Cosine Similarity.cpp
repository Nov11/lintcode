class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        double dot = 0;
        int len = A.size();
        double sqrA = 0;
        double sqrB = 0;
        for(int i = 0; i < len; i++){
            dot += A[i] * B[i];
            sqrA += A[i] * A[i];
            sqrB += B[i] * B[i];
        }
        
        if(abs(sqrA) < 0.001 || abs(sqrB) < 0.001){
            return 2;
        }
        
        return dot / sqrt(sqrA) / sqrt(sqrB);
    }
};
