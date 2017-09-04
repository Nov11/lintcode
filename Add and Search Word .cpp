
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
    bool wildcardMatch(TrieNode* cur, string& word, int idx){
        for(int i = idx; i < word.size(); i++){
            char c = word[i];
            if(c != '.'){
                if(cur->hash[c] == nullptr){return false;}
                cur = cur->hash[c];
            }else{
                for(auto item : cur->hash){
                    if(item.second == nullptr){continue;}
                    auto ret = wildcardMatch(item.second, word, i + 1);
                    if(ret){return true;}
                }
                return false;
            }
        }
        return cur != nullptr && cur->isWord;
    }
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
    
    bool wildCardMatch(string word){
        return wildcardMatch(root, word, 0);
    }
private:
    TrieNode* root;
};
class WordDictionary {
    Trie trie;
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return trie.wildCardMatch(word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");