class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        int olen = originalStr.size();
        if(olen >= size){return originalStr;}
        
        string result(size, padChar);
        
        for(int i = size - originalStr.size(), j = 0; i < size; i++, j++){
            result[i] = originalStr[j];
        }
        
        return result;
    }
};