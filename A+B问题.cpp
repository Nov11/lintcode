class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        int carry = 0;
        int result = 0;
        for(int i = 0; i < 32; i++){
            int bitFromB = b & (1 << i);
            int bitFromA = a & (1 << i);
            if(bitFromB ^ bitFromA){
                //not equal,must be a 'one' there
                if(carry){
                    carry = 1;
                    //bit in result is 0
                }else{
                    //carry is still 0
                    result |= (1 << i);
                }
            }else{
                if(carry){
                    result |= (1<<i);
                }
                if(bitFromB){
                    carry = 1;
                }else{
                    carry = 0;
                }
            }
        }
        return result;
    }
};