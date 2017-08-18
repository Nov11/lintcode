#include <list>
class LFUCache {
    unordered_map<int, int> kv;
	unordered_map<int, int> cnt;
	map<int, list<int> > hash;
	int cap;

	void increaseFrequency(int key) {
		int c = cnt[key];
		cnt[key]++;
		auto& lst = hash[c];
		lst.remove(key);
		if (lst.empty()) { hash.erase(c); }
		hash[c + 1].push_back(key);
	}
public:
	// @param capacity, an integer
	LFUCache(int capacity) {
		// Write your code here
		cap = capacity;
	}

	// @param key, an integer
	// @param value, an integer
	// @return nothing
	void set(int key, int value) {
		// Write your code here
		if(cap == 0){return;}
		if (kv.find(key) == kv.end()) {
			if (kv.size() == cap) {
				auto leastCnt = hash.begin();
				auto& lst = leastCnt->second;
				auto delThis = lst.front();
				kv.erase(delThis);
				cnt.erase(delThis);
				lst.pop_front();
				if (lst.empty()) {
					hash.erase(leastCnt);
				}
			}
			kv[key] = value;
			hash[1].push_back(key);
			cnt[key] = 1;
		}
		else {
			//int c = cnt[key];
			//auto& lst = hash[c];
			//lst.remove(key);
			//if (lst.empty()) { hash.erase(c); }
			//cnt[key] = 1;
			//kv[key] = value;
			//hash[1].push_back(key);
            //not the same as I thought, Ohhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
			increaseFrequency(key);
			kv[key] = value;
		}
	}

	// @return an integer
	int get(int key) {
		// Write your code here
		if(cap == 0){return -1;}
		if (kv.find(key) == kv.end()) { return -1; }
		increaseFrequency(key);
		return kv[key];
	}
};