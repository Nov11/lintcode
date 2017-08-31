class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if(this == &object){return *this;}
        char* ptr = nullptr;
        if(object.m_pData == nullptr){
            //nothing
        }else{
            int len = strlen(object.m_pData);
            ptr = new char[len + 1];
            for(int i = 0; i < len; i++){
                ptr[i] = object.m_pData[i];
            }
            ptr[len] = NULL;
        }
        
        delete m_pData;
        m_pData = ptr;
        return *this;
    }
};