class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        if(A.empty()){return A;}
        
        vector<char> v{A[0]};
        for(int i = 1; i < A.size(); i++){
            while(!v.empty() && v.back() > A[i] && k){
                k--;
                v.pop_back();
            }
            v.push_back(A[i]);
        }
        
        while(k){
            k--;
            v.pop_back();
        }
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == '0'){cnt++;}
            else{break;}
        }
        
        return string(v.begin() + cnt, v.end());
    }
};
