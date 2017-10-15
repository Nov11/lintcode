class Solution {
    int partition(vector<int>& A){
        int beg = 0;
        int end = A.size();
        
        while(beg < end){
            while(beg < end && A[beg] > 0){beg++;}
            while(end - 1 >= 0 && A[end - 1] < 0){end--;}
            if(beg < end - 1){
                swap(A[beg++], A[end-- - 1]);
            }else{
                break;
            }
        }
        return beg;
    }
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int>& A){
        int pos = partition(A);
        int len = A.size();
        
        int idx = 0;
        bool pickFirstHalf = true;
        if(!(pos * 2 >= len)){
            swap(A[0], A[pos]);
            pos++;
            idx = 1;
        }
        
        for(int i = idx; i < len; i++, pickFirstHalf = !pickFirstHalf){
            if(!pickFirstHalf){
                swap(A[i], A[pos]);
                pos++;
            }
        }
    }
    void rerangeOld(vector<int> &A) {
        // write your code here
        int pos = 0;
        for(auto item : A){
            if(item > 0){pos++;}
        }
        int len = A.size();
        int beg = 0;
        if(len > pos * 2){
            for(auto& item : A){
                if(item < 0){
                    swap(A[0], item);
                }
            }
            beg = 1;
        }
        bool needpos = true;
        for(; beg < len; beg++, needpos = !needpos){
            if(needpos && A[beg] > 0 || !needpos && A[beg] < 0){
                continue;
            }
            for(int i = beg + 1; i < len; i++){
                if(needpos && A[i] > 0 || !needpos && A[i] < 0){
                    swap(A[i], A[beg]);
                }
            }
        }
    }
};