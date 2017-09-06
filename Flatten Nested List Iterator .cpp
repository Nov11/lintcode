/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    queue<int> q;
    void work(const vector<NestedInteger> &nestedList){
        for(auto item : nestedList){
            if(item.isInteger()){
                q.push(item.getInteger());
            }else{
                work(item.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        work(nestedList);
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int ret = q.front();
        q.pop();
        return ret;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */