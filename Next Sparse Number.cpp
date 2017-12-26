class Solution {
  bool isSparse(int &n) {
    for (int i = 0; i < 31; i++) {
      int mask = 3 << i;
      int tmp = n & mask;
      tmp >>= i;
      if (tmp == 3) {
        n = (n >> (i + 2)) << (i + 2);
        n = n + (1 << (i + 2));
        return false;
      }
    }
    return true;
  }
 public:
  /*
   * @param : a number
   * @return: return the next sparse number behind x
   */
  int nextSparseNum(int x) {
    // write your code here
    for (int i = x; i <= INT_MAX;/*get new value in isSparse*/) {
      if (isSparse(i)) {
        return i;
      }
    }
    return -1;
  }
};
