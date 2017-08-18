class Solution {
    int bsFirst(vector<int>& nums, int beg, int end, int target){
        if(beg >= end){return -1;}
        while(beg < end){
            int mid = beg + (end - beg) / 2;
            if(nums[mid] >= target){end = mid;}
            else{beg = mid + 1;}
        }
        return beg;
    }
    
    int bsLast(vector<int>& nums, int beg, int end, int target){
        if(beg >= end){return -1;}
        while(beg < end){
            int mid = beg + (end - beg) / 2;
            if(nums[mid] <= target){beg = mid + 1;}
            else{end = mid;}
        }
        return beg - 1;
    }
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        auto l = bsFirst(A, 0, A.size(), target);
        if(l < 0 || l >= A.size() ||  A[l] != target){return {-1,-1};}
        return {l, bsLast(A, 0, A.size(), target)};
    }
};