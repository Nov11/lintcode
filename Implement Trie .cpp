/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        
    }
    unordered_map<char, TrieNode*> hash;
    bool isWord = false;
};

class Trie {
    TrieNode* work(string& word){
        TrieNode* ptr = root;
        for(auto item : word){
            if(ptr->hash[item] == nullptr){return nullptr;}
            ptr = ptr->hash[item];
        }
        return ptr;
    }
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* ptr = root;
        for(auto item : word){
            if(ptr->hash[item] == nullptr){
                ptr->hash[item] = new TrieNode;
            }
            ptr = ptr->hash[item];
        }
        ptr->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto ret = work(word);
        return ret != nullptr && ret->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto ret = work(prefix);
        return ret != nullptr;
    }

private:
    TrieNode* root;
};