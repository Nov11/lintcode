class Solution {
	struct Node {
		map<char, Node*> hash;
		bool isWord = false;
		string str;
	};

	Node root;
	void build(const string& s) {
		Node* ptr = &root;
		for (auto item : s) {
			map<char, Node*>& link = ptr->hash;
			if (link.find(item) == link.end()) {
				Node* n = new Node;
				link[item] = n;
			}
			ptr = link[item];
		}
		ptr->isWord = true;
		ptr->str = s;
	}

	bool remove(string s, int idx, Node* ptr) {
		if (ptr == nullptr || s.empty()) { return false; }
		if (idx == s.size()) {
			ptr->isWord = false;
		}
		else {
			auto ret = remove(s, idx + 1, ptr->hash[s[idx]]);
			if (ret) {
				ptr->hash.erase(s[idx]);
			}
		}

		if (ptr->hash.empty()) {
			return true;
		}

		return false;
	}

	bool valid(int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n) {
			return false;
		}
		return true;
	}
	void work(vector<vector<char>>& board, int i, int j, Node* ptr, vector<string>& result) {
		if (ptr == nullptr || !valid(i, j) || board[i][j] == '!') {
			return;
		}
		char c = board[i][j];

		map<char, Node*>&link = ptr->hash;
		if (link.empty() || link.find(c) == link.end()) {
			return;
		}
		Node* next = link[c];
		bool endprobe = next->hash.empty();
		if (next->isWord) {
			result.push_back(next->str);
			remove(next->str, 0, &root);
		}
		if (!endprobe) {
			board[i][j] = '!';
			for (int iter = 0; iter < 4; iter++) {
				work(board, row[iter] + i, col[iter] + j, next, result);
			}
		}
		board[i][j] = c;
	}

	int row[4] = { 0,0,1,-1 };
	int col[4] = { 1,-1,0,0 };
	int m;
	int n;
public:
	/*
	* @param board: A list of lists of character
	* @param words: A list of string
	* @return: A list of string
	*/
	vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
		// write your code here
		vector<string> result;
		m = board.size();
		if (m == 0) { return result; }
		n = board[0].size();
		if (n == 0) { return result; }

		for (auto& item : words) {
			build(item);
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				work(board, i, j, &root, result);
			}
		}

		return result;
	}
};