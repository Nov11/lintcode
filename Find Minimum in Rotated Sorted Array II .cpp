class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int len = num.size();
        if(len == 1){return num[0];}
        
        int b = 0;
        int e = len;
        while(b < e){
            if(b + 1 == e){return num[b];}
            if(num[b] == num[e - 1]){e--;continue;}
            if(num[b] < num[e - 1]){
                return num[b];
            }
            //num[b] > num[e - 1]
            int mid = b + (e - b) / 2;
            if(num[mid] >= num[b]){
                b = mid + 1;
            }else{
                b++;
                e = mid + 1;
            }
        }
    }
};