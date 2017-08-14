class Solution {
    map<pair<int,int>, int> hash;
	int work(vector<vector<int>>& tri, int row, int col) {
	    auto p = make_pair(row, col);
	    if(hash.find(p) != hash.end()){return hash[p];}
	    
		if (tri.size() == row + 1) {
			return tri[row][col];
		}
		int minVal = INT_MAX;

        minVal = min(minVal, work(tri, row + 1, col));
        minVal = min(minVal, work(tri, row + 1, col + 1));
        
		auto result = minVal + tri[row][col];
		hash[p] = result;
		return result;
	}
public:
	/**
	* @param triangle: a list of lists of integers.
	* @return: An integer, minimum path sum.
	*/
	int minimumTotal(vector<vector<int> > &triangle) {
		// write your code here
		if (triangle.empty()) { return 0; }
		return work(triangle, 0, 0);
	}
};