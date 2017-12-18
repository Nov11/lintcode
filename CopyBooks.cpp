class Solution {
    bool work(vector<int>& pages, int len, int k){
        int acc = 0;
        for(int i = 0; i < pages.size(); i++){
            if(len < pages[i] || k == 0){
                return false;
            }
            if(acc + pages[i] <= len){
                acc += pages[i];
            }else{
                acc = pages[i];
                k--;
            }
        }
        return k > 0;
    }
public:
    /*
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int b = 0;
        int sum = accumulate(pages.begin(), pages.end(), 0);
        int e = sum;
        while(b < e){
            int mid = b + (e - b) / 2;
            cout << mid << endl;
            if(work(pages, mid, k)){
                e = mid;
            }else{
                b = mid + 1;
            }
        }
        return b;
    }
}
