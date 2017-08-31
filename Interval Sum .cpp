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
	class SegmentTreeNode {
	public:
		int start, end;
		long long sum;
		SegmentTreeNode *left, *right;
		SegmentTreeNode(int start, int end) {
			this->start = start, this->end = end;
			this->left = this->right = NULL;
			sum = 0;
		}
	};
	using Node = SegmentTreeNode;
	long long query(SegmentTreeNode * root, int start, int end) {
		// write your code here
		if (!root || root->start > start || root->end < end) { return -1; }
		if (root->start == start && root->end == end) {
			return root->sum;
		}

		if (end <= (root->start + root->end) / 2) {
			return query(root->left, start, end);
		}
		if (start >= (root->start + root->end) / 2 + 1) {
			return query(root->right, start, end);
		}

		auto left = query(root->left, start, (root->start + root->end) / 2);
		auto right = query(root->right, (root->start + root->end) / 2 + 1, end);
		return left + right;
	}
	SegmentTreeNode * build(int start, int end, vector<int>& nums) {
		// write your code here
		if (start > end) { return nullptr; }

		Node* result = new Node(start, end);

		if (start != end) {
			int sr = 0;
			int sl = 0;
			result->left = build(start, (start + end) / 2, nums);
			result->right = build((start + end) / 2 + 1, end, nums);
			result->sum = result->left->sum + result->right->sum;
		}
		else {
			result->sum = nums[start];
		}
		return result;
	}
public:
	/*
	* @param A: An integer list
	* @param queries: An query list
	* @return: The result list
	*/
	vector<long long> intervalSum(vector<int> A, vector<Interval> queries) {
		// write your code here
		Node* root = build(0, A.size(), A);
		vector<long long> result;
		for (auto item : queries) {
			auto ret = query(root, item.start, item.end);
			result.push_back(ret);
		}

		return result;
	}
};