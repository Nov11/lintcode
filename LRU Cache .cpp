#include <list>
class LRUCache {
	map<int, list<pair<int, int>>::iterator> hash;
	list<pair<int,int>> lst;
	int cap;
public:
	/*
	* @param capacity: An integer
	*/LRUCache(int capacity) :cap(capacity) {
	// do intialization if necessary
}

	  /*
	  * @param key: An integer
	  * @return: An integer
	  */
	  int get(int key) {
		  // write your code here
		  if (hash.find(key) == hash.end()) {
			  return -1;
		  }
		  auto item = hash[key];
		  lst.insert(lst.begin(), *item);
		  lst.erase(item);
		  hash[key] = lst.begin();

		  return hash[key]->second;
	  }

	  /*
	  * @param key: An integer
	  * @param value: An integer
	  * @return: nothing
	  */
	  void set(int key, int value) {
		  // write your code here
		  if (hash.find(key) != hash.end()) {
			  auto item = hash[key];
			  lst.insert(lst.begin(), *item);
			  lst.erase(item);
			  hash[key] = lst.begin();
			  hash[key]->second = value;
			  return;
		  }
		  if (hash.size() == cap) {
			  auto k = lst.back().first;
			  lst.pop_back();
			  hash.erase(k);
		  }
		  lst.insert(lst.begin(), make_pair(key, value));
		  hash[key] = lst.begin();
	  }
};