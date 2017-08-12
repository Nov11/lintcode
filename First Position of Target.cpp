class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int beg = 0;
        int end = array.size();
        
        while(beg < end){
            int mid = beg + (end - beg) / 2;
            if(array[mid] >= target){end = mid;}
            else{beg = mid + 1;}
        }
        if(array[beg] == target){return beg;}
        return -1;
    }
};