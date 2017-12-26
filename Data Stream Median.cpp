class Solution {

  /**
   * @param nums: A list of integers.
   * @return: The median of numbers
   */
  vector<int> medianII_old(vector<int> &nums) {
    // write your code here
    vector<int> result;
    if (nums.size() == 0) {
      return result;
    }
    result.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      result.push_back(median(&nums[0], &nums[0] + i + 1, i / 2));
    }
    return result;
  }
  int partition(int *beg, int *end) {
    int pivot = *beg;
    int *lt = beg + 1;
    int *lg = end;
    while (true) {
      while (lt < end && *lt < pivot)lt++;
      while (lg > beg + 1 && *(--lg) >= pivot);
      if (lt > lg) {
        break;
      }
      int tmp = *lt;
      *lt = *lg;
      *lg = tmp;
      lt++;
      lg--;
    }
    *beg = *lg;
    *lg = pivot;
    return lg - beg;
  }
  int median(int *beg, int *end, int idx) {
    int ret = partition(beg, end);
    if (ret == idx)return beg[ret];
    else if (ret < idx)return median(beg + ret + 1, end, idx - ret - 1);
    else return median(beg, beg + ret, idx);
  }

  int work(vector<int> &nums, int index) {

  }
  priority_queue<int, vector<int>, greater<int>> minHeap;
  priority_queue<int> maxHeap;
  int work(int v) {
    if(maxHeap.empty()){
      maxHeap.push(v);
      return v;
    }

    if(maxHeap.size() == minHeap.size()){
      if(v > minHeap.top()){
        minHeap.push(v);
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }else{
        maxHeap.push(v);
      }
    }else{
      if(!minHeap.empty() && v>=minHeap.top()){
        minHeap.push(v);
      }else{
        maxHeap.push(v);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
    }

    return maxHeap.top();
  }
 public:
  vector<int> medianII(vector<int> &nums) {
    // write your code here
    vector<int> result;
    if (nums.empty()) { return result; }
    for (int i = 0; i < nums.size(); i++) {
      result.push_back(work(nums[i]));
    }
    return result;
  }
};
