class RandomizedSet {
    unordered_map<int, int> hash;
    vector<int> v;
public:
    RandomizedSet() {
        // do initialize if necessary
        srand(time(nullptr));
    }
    
    // Inserts a value to the set
    // Returns true if the set did not already contain the specified element or false
    bool insert(int val) {
        // Write your code here
        if(hash.find(val) != hash.end()){
            return false;
        }
        v.push_back(val);
        hash[val] = v.size() - 1;
        return true;
    }
    
    // Removes a value from the set
    // Return true if the set contained the specified element or false
    bool remove(int val) {
        // Write your code here
        if(hash.find(val) == hash.end()){return false;}
        int idx = hash[val];
        v[idx] = v.back();
        v.pop_back();
        hash.erase(val);
        if(hash.find(v[idx]) != hash.end()){
            hash[v[idx]] = idx;
        }
        return true;
    }
    
    // Get a random element from the set
    int getRandom() {
        // Write your code here
        return v.empty() ? -1 : v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */