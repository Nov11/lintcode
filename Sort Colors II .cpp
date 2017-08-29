class Solution{
    void sort(vector<int>& colors, int mini, int maxi, int& beg, int& end){
        if(mini == maxi || beg == end){return;}
        
        int pmid = beg;
        int pmaxi = end;
        for(int i = beg; i < pmaxi; i++){
            if(colors[i] == mini){
                swap(colors[i], colors[pmid]);
                pmid++;
            }else if(colors[i] == maxi){
                swap(colors[i], colors[pmaxi - 1]);
                pmaxi--;
                i--;
            }
        }
        
        beg = pmid;
        end = pmaxi;
    }
    void partition(vector<int>& colors, int mini, int maxi, int beg, int end){
        if(mini == maxi || beg >= end){return;}
        
        int c = mini + (maxi - mini) / 2;
        int low = beg;
        int high = end;
        for(int i = beg; i < high; i++){
            if(colors[i] < c){
                swap(colors[low], colors[i]);
                low++;
            }else if(colors[i] > c){
                swap(colors[i], colors[high - 1]);
                high--;
                i--;
            }
        }
        
        partition(colors, mini, c - 1, beg, low);
        partition(colors, c + 1, maxi, high, end);
    }
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int beg = 0;
        int end = colors.size();
        // for(int i = k, j = 1; i > j; i--, j++){
        //     sort(colors, j, i, beg, end);
        // }
        partition(colors, 1, k, 0, colors.size());
    }
};