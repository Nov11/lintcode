class Solution {
	struct Node {
		Node* left;
		Node* right;
		int begin;
		int end;
		int sum = 0;
		Node(int b, int e) :begin(b), end(e), left(nullptr), right(nullptr){}
	};
	Node* root;
	Node* build(int first, int last, vector<int>&A) {
		if (first > last) { return nullptr; }

		Node* result = new Node(first, last);

		if (first == last) {
			result->sum = A[first];
			return result;
		}

		int mid = first + (last - first) / 2;
		result->left = build(first, mid, A);
		result->right = build(mid + 1, last, A);
		result->sum = result->right->sum + result->left->sum;

		return result;
	}

	long long sum(int first, int last, Node* root) {
		if (first > last) {
			return 0;
		}

		if (!root || root->begin > last || root->end < first) {
			return 0;
		}

		first = max(first, root->begin);
		last = min(last, root->end);

		if (root->begin == first && root->end == last) {
			return root->sum;
		}

		int mid = root->begin + (root->end - root->begin) / 2;
		//first = max(root->begin, first);
		//last = min(root->end, last);

		if (last <= mid) {
			return sum(first, last, root->left);
		}else if (first >= mid + 1) {
			return sum(first, last, root->right);
		}
		long long result = 0;
		result += sum(first, mid, root->left);
		result += sum(mid + 1, last, root->right);

		return result;
	}

	void modi(Node* root, int index, int value) {
		if (!root) { return; }
		if (index < root->begin || index > root->end) {
			return;
		}

		if (root->begin == root->end && root->begin == index) {
			root->sum = value;
			return;
		}

		int mid = root->begin + (root->end - root->begin) / 2;
		if (mid >= index) {
			modi(root->left, index, value);
		}
		else {
			modi(root->right, index, value);
		}

		root->sum = root->left->sum + root->right->sum;
	}
public:
	/* you may need to use some attributes here */

	/*
	* @param A: An integer array
	*/
	Solution(vector<int> A) {
		// do intialization if necessary
		root = build(0, A.size()-1, A);
	}

	/*
	* @param start: An integer
	* @param end: An integer
	* @return: The sum from start to end
	*/
	long long query(int start, int end) {
		// write your code here
		return sum(start, end, root);
	}

	/*
	* @param index: An integer
	* @param value: An integer
	* @return: nothing
	*/
	void modify(int index, int value) {
		// write your code here
		modi(root, index, value);
	}
};