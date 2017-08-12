class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == nullptr || target == nullptr){return -1;}
        const char* p1 = source;
        const char* s1 = source;
        const char* p2 = target;

        while(*p1 != NULL && *p2 != NULL){
            if(*p1 == *p2){p1++;p2++;}
            else{p1 = ++s1;p2 = target;}
        }
        if(*p2 == NULL){return p1 - source - strlen(target);}
        return -1;
    }
};
