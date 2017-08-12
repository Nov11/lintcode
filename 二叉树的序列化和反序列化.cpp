class Solution {
public:
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TreeNode *root) {
		// write your code here
		if (root == nullptr) { return ""; }
		string left = serialize(root->left);
		string right = serialize(root->right);
		return "(" + left + ")" + to_string(root->val) + "(" + right + ")";
	}

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode *deserialize(string data) {
		// write your code here
		if (data.empty()) { return nullptr; }
		int leftBracket = 0;
		int pos = 0;
		for (; pos < data.size(); pos++) {
			if (data[pos] == '(') { leftBracket++; }
			else if (data[pos] == ')') { leftBracket--; }
			if (leftBracket == 0) { break; }
		}
		// 		if (pos == data.size()) {
		// 			return nullptr;
		// 		}

		int nextLeftBracket = pos + 1;
		while (nextLeftBracket < data.size() && data[nextLeftBracket] != '(') {
			nextLeftBracket++;
		}
		// 		assert(nextLeftBracket != data.size());
		string val = data.substr(pos + 1, nextLeftBracket - pos);
		// 		if (val.empty()) {
		// 			return nullptr;
		// 		}
		TreeNode * tn = new TreeNode(stoi(val));
		tn->left = deserialize(data.substr(1, pos - 1));
		tn->right = deserialize(data.substr(nextLeftBracket + 1, data.size() - 1 - (nextLeftBracket + 1)));
		return tn;
	}
};